#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "mensaje.h"
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_

class SocketMulticast
{
private:
    int s;
    int contMessage;
    int lastMessage;
    struct ip_mreq multicast;
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
public:
    SocketMulticast(int puerto);
    ~SocketMulticast();
    int enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores);
    int recibeConfiable(PaqueteDatagrama &p);
    int recibe(PaqueteDatagrama & paqueteDatagrama);
    int envia(PaqueteDatagrama & paqueteDatagrama, unsigned char ttl); //Se une a un grupo multicast, recibe la IP multicast
    void unirseGrupo(char *); //Se sale de un grupo multicast, recibe la IP multicast
    void salirseGrupo(char *);
};

#endif