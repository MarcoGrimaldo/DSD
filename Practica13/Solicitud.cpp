#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;

unsigned int contRequest = 0;

Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0); //7200
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
    struct mensaje msj; 
    msj.messageType = 0;
    msj.requestId = contRequest;
    printf("Operacion num: %u\n", contRequest);
    memcpy(msj.IP, IP, strlen(IP));
    msj.puerto = puerto;
    msj.operationId = operationId;
    memcpy(msj.arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(sizeof(mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)&msj);
    //socketlocal->envia(paquete);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    //Nuevo codigo
    short contador = 0;
    while (socketlocal->recibeTimeout(respuesta, 2, 500000) == -1 && contador < 7){
        contador++;
        socketlocal->envia(paquete);
        printf("%S\n", "Tiempo de recepción transcurrido");
    }
    
    if (contador == 7) {
		cout << "Servidor no esta disponible, intente mas tarde." << endl;
		exit(0);
	}
	else
	{
		struct mensaje *msj = (struct mensaje *)respuesta.obtieneDatos();
		contRequest++;
		return (char *)msj->arguments;
	}
}