#include "Respuesta.h"
#include <iostream>

PaqueteDatagrama p = PaqueteDatagrama(65000);

Respuesta::Respuesta(int port){
    socketlocal = new SocketDatagrama(port);
    contRequest = 0;
}

struct mensaje* Respuesta::getRequest(void){
    //PaqueteDatagrama p(sizeof(struct mensaje));
    
    int tam = socketlocal->recibe(p);
    if (tam == -1)
    {
        perror("Recvfrom failed");
    }

    struct mensaje *msg = (struct mensaje*) p.obtieneDatos();

    unsigned int reqId = 0;
    memcpy(&reqId, &msg->requestId, sizeof(msg->requestId));

    if(reqId < contRequest) {
        std::cout << "Paquete repetido. Desechando.." << endl;
        return NULL;
    }
    else {
        contRequest++;
        return (struct mensaje*)msg;
    }

}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    struct mensaje *msj = (struct mensaje *)malloc(sizeof(struct mensaje));

    msj->messageType = 1;
    msj->operationId = 0;
    msj->requestId = 0;
    memcpy(msj->arguments, respuesta, strlen(respuesta));
    
    p.inicializaDatos((char *)msj);

    socketlocal->envia(p);
}