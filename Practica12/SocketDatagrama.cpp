#include "SocketDatagrama.h"

SocketDatagrama::SocketDatagrama(int puerto){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la direccion del servidor */
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));

    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto); // si es 0, el puerto será asignado por el Sistema Operativo
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
    close(s);
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    int enviados = 0;
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    enviados = sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));

    return enviados;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos)
{
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	unsigned int len = sizeof(direccionForanea);
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &len);
	if (rec < 0)
	{
		if (errno == EWOULDBLOCK)
		{
			fprintf(stderr, "Tiempo para recepcion transcurrido\n");
			return -1;
		}
		else
		{
			fprintf(stderr, "Error en recvfrom\n");
			return rec;
		}
	}
	else
	{
		unsigned char ip[4];
		memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);
		string ip1 = to_string(ip[0]);
		string ip2 = to_string(ip[1]);
		string ip3 = to_string(ip[2]);
		string ip4 = to_string(ip[3]);
		ip1.append(".");
		ip1.append(ip2);
		ip1.append(".");
		ip1.append(ip3);
		ip1.append(".");
		ip1.append(ip4);

		char dirIp[16];
		strcpy(dirIp, ip1.c_str());
		p.inicializaIp(dirIp);
		p.inicializaPuerto(direccionForanea.sin_port);
	}
	return rec;
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    int recibidos = 0;
    char datos[p.obtieneLongitud()];
    char aux[INET_ADDRSTRLEN];
    socklen_t clilen = sizeof(direccionForanea);
    recibidos = recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), aux, INET_ADDRSTRLEN);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(aux);
    p.inicializaDatos(datos);

    return recibidos;
}