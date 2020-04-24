#include "SocketMulticast.h" 
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

SocketMulticast::SocketMulticast(int puerto) {
    contMessage = 1;
	lastMessage = 0;
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    int reuse = 1;
    if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
        printf("Error al llamar a la función setsockopt\n");
        exit(0);
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY inet_addr(argv[1])
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketMulticast::~SocketMulticast() {
    close(s);
}

void SocketMulticast::unirseGrupo(char* ip) {
    multicast.imr_multiaddr.s_addr = inet_addr(ip);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    int res=setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
    if(res<0){
        std::cout<<"No te uniste el grupo"<<std::endl;
    }else{
        std::cout<<"Te uniste al grupo "<<ip<<std::endl;
    }
}

void SocketMulticast::salirseGrupo(char *ip) {
    if ( multicast.imr_multiaddr.s_addr == inet_addr(ip) ) {
        setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));       
    }
}

int SocketMulticast::envia(PaqueteDatagrama &paqueteDatagrama, unsigned char ttl) {
    
    int n = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));

    if ( n < 0 ) {
         printf("Ha ocurrido un error al enviar el paquete \n");
    } else {
        int client = sizeof(direccionForanea);
        bzero((char *)&direccionForanea, sizeof(direccionForanea));
        direccionForanea.sin_family = AF_INET;
        direccionForanea.sin_addr.s_addr = inet_addr(paqueteDatagrama.obtieneDireccion());
        direccionForanea.sin_port = htons(paqueteDatagrama.obtienePuerto());
        sendto(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t)client);
    }
    
}

int SocketMulticast::enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores){
	struct mensaje m;
	m.idMessage = contMessage;
	memcpy(m.arguments, p.obtieneDatos(), 4);
	printf("\n\nidMessage: %d\n", contMessage);
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&ttl, sizeof(ttl));
    direccionForanea.sin_family = PF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	int resp = sendto(s, (char *)&m, sizeof(m), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));

	int cont = 0;
	SocketDatagrama *s_ack = new SocketDatagrama(7070);
	PaqueteDatagrama ack = PaqueteDatagrama(4);

	while(cont < num_receptores) {
		int resp_ack = s_ack->recibeTimeout(ack, 2, 500);
		if(resp_ack == -1) {
			std::cout << "Acuse no recibido. Paquete perdido.." << std::endl;
			s_ack-> ~SocketDatagrama();
			return -1;
		}
		cont++;
		std::cout << "Acuse recibido" << std::endl;
	}

	s_ack->~SocketDatagrama();
	contMessage++;
	return resp;
}

int SocketMulticast::recibe(PaqueteDatagrama &paqueteDatagrama) {
    int client = sizeof(direccionForanea);
    int n = recvfrom(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    paqueteDatagrama.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    paqueteDatagrama.inicializaPuerto(ntohs(direccionForanea.sin_port));
    
    return n;
}

int SocketMulticast::recibeConfiable(PaqueteDatagrama &p){
	unsigned int len = sizeof(direccionForanea);
	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &len);
	if(rec == -1){
		return rec;
	}

	unsigned char ip[4];
	memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);
	std::string ip1 = std::to_string(ip[0]);
	std::string ip2 = std::to_string(ip[1]);
	std::string ip3 = std::to_string(ip[2]);
	std::string ip4 = std::to_string(ip[3]);
	ip1.append(".");
	ip1.append(ip2);
	ip1.append(".");
	ip1.append(ip3);
	ip1.append(".");
	ip1.append(ip4);
	char dirIp[16];
	strcpy(dirIp, ip1.c_str());

	int id = 0;
	struct mensaje* m = (struct mensaje*) p.obtieneDatos();
	memcpy(&id, &m->idMessage, 4);
	printf("\nLastMessage: %u SMS->idMessage: %d\n", lastMessage, id);
	SocketDatagrama *s_ack = new SocketDatagrama(0);
	PaqueteDatagrama p_resp = PaqueteDatagrama((char*)&id, 4, dirIp, 7070);
	s_ack->envia(p_resp);
	std::cout<< "Acuse enviado" << std::endl;
	s_ack->~SocketDatagrama();

	if(id <= lastMessage){
		std::cout << "Paquete repetido. Desechando.." << std::endl;
		return -1;
	}
	else {
		p.inicializaIp(dirIp);
		p.inicializaDatos((char*)&m->arguments);
		p.inicializaPuerto(direccionForanea.sin_port);
		lastMessage++;
		return rec;
	}
}

