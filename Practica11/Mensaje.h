#ifndef _MENSAJE_
#define _MENSAJE_

#define TAM_MAX_DATA 4000
#define suma 1

struct mensaje{
    int messageType;
    unsigned int requestId;
    char IP[16];
    int puerto;
    int operationId;
    char arguments[TAM_MAX_DATA];
};
#endif