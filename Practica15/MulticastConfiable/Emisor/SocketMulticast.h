#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_
#include "PaqueteDatagrama.h"
#include <errno.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "mensaje.h"
#include "SocketDatagrama.h"
using namespace std;

class SocketMulticast{
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama &p);
        int recibeConfiable(PaqueteDatagrama &p);
        int envia(PaqueteDatagrama &p, unsigned char ttl);
        int enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores);
        void unirseGrupo(char *);
        void salirseGrupo(char *);
    
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        struct ip_mreq multicast;
        int contMessage;
        int lastMessage;
        int s; //ID socket
        SocketDatagrama *ack; //Acuse
};
#endif