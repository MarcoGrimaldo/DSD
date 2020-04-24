#include "PaqueteDatagrama.h"
#include "Timeval.h"
#include <netinet/in.h>

#ifndef SOCKETDATAGRAMA_H_
#define SOCKECTDATAGRAMA_H_

class SocketDatagrama{

private:
    struct Timeval timeval;
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s; //ID socket

public:
    SocketDatagrama(int);
    ~SocketDatagrama();
    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama & p);
    int recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos);
    //Envía un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama & p);
    struct sockaddr_in getDirForanea();
    
};

#endif
