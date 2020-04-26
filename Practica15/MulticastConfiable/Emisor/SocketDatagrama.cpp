#include "SocketDatagrama.h"
#include <iostream>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));

	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;

	if (pto == 0)
		direccionLocal.sin_port = htons(pto);
	else
		direccionLocal.sin_port = pto;

	if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
}

SocketDatagrama::~SocketDatagrama() {
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
	unsigned int len = sizeof(direccionForanea);
	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, &len);
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
	return rec;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos) {
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	unsigned int len = sizeof(direccionForanea);
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &len);
	if (rec < 0) {
		if (errno == EWOULDBLOCK) {
			fprintf(stderr, "Tiempo para recepción transcurrido\n");
			return -1;
		}
		else {
			fprintf(stderr, "Error en recvfrom\n");
			return rec;
		}
	}
	else {
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

int SocketDatagrama::envia(PaqueteDatagrama &p) {
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = p.obtienePuerto();
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}