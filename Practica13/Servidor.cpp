#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include "Respuesta.h"
using namespace std;

int main()
{
    Respuesta respuesta(7200);
    printf("Esperando cliente.....\n");
    int nbd = 0;
    struct mensaje *msg;
    //string ndbstring;

    while(true){
        msg = respuesta.getRequest();

        if (msg != NULL)
        {
            int n = 0;
            memcpy(&n, &msg->arguments, 4);
            nbd = nbd + n;
            printf("\nRecibido: %d \nNBD: %d\n", n, nbd);
        
        respuesta.sendReply((char *)&nbd, msg->IP, msg->puerto);
        }
    
    }
}
