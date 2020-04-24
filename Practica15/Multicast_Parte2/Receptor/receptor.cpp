#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TAM_MAX_DATA 650

int main(int argc, char const *argv[])
{
    int numeros[2];
    char* ip = (char *) argv[1];
    int puerto = atoi(argv[2]);

    SocketMulticast socketMulticast(puerto);
    PaqueteDatagrama paqueteDatagrama_Recepcion(2 * sizeof(int));

    socketMulticast.unirseGrupo(ip);     

    socketMulticast.recibe(paqueteDatagrama_Recepcion);

    socketMulticast.salirseGrupo(ip);

    memcpy(&numeros,paqueteDatagrama_Recepcion.obtieneDatos(),2 * sizeof(int));

    std::cout << "Cliente: \n" <<  "IP:" << paqueteDatagrama_Recepcion.obtieneDireccion();
    std::cout << ", Puerto: " << paqueteDatagrama_Recepcion.obtienePuerto() << "\n";
    int aux = numeros[0] + numeros[1];
    std::cout << "Numeros recibidos: a = " << numeros[0] <<  ", b = " << numeros[1] << std::endl;
    int* resp = &(aux);


    SocketDatagrama socketDatagrama(7200);
    PaqueteDatagrama paqueteDatagrama_Envio((char*) resp ,sizeof(int),paqueteDatagrama_Recepcion.obtieneDireccion(),7200);
    socketDatagrama.envia(paqueteDatagrama_Envio);
    

    return 0;
}
