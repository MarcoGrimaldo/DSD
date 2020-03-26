#include "Solicitud.h"

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
    socketlocal->recibe(respuesta);
    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

    return msj_respuesta->arguments;
}