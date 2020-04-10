#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;

Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0); //7200
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
    msj->messageType = 0;
    msj->requestId = 1;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(sizeof(mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);
    socketlocal->envia(paquete);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    int tam = socketlocal->recibeTimeout(respuesta,2,500);

    int n = 1;

    while (tam == -1 && n < 7) {
		socketlocal->envia(paquete);
		tam = socketlocal->recibeTimeout(respuesta, 2, 500);
		n++;
	}

	if (n == 7) {
		cout << "Servidor no disponible, intente despues." << endl;
		exit(0);
	}
	else {
		cout << "\nMensaje recibido" << endl;
		cout << "Direccion: " << respuesta.obtieneDireccion() << endl;
		cout << "Puerto: " << respuesta.obtienePuerto() << endl;
		struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
        msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

        return msj_respuesta->arguments;
	}

    
}