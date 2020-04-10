#ifndef _SOLICITUD_
#define _SOLICITUD_

#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Mensaje.h"
#include <cstdio>
#include <cstdlib>

class Solicitud{
    public:
        Solicitud();
        char *doOperation(char *IP, int puerto, int operationId, char *arguments);
    private:
        SocketDatagrama *socketlocal;
};
#endif