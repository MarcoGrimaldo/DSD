#include "SocketMulticast.h" 
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

SocketMulticast::SocketMulticast(int puerto) {
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

int SocketMulticast::recibe(PaqueteDatagrama &paqueteDatagrama) {
    int client = sizeof(direccionForanea);
    int n = recvfrom(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    paqueteDatagrama.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    paqueteDatagrama.inicializaPuerto(ntohs(direccionForanea.sin_port));
    
    return n;
}

