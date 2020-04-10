#include "Solicitud.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Solicitud cliente;
    if(argc < 3){
        printf("Error: Indica la IP y el numero de iteraciones\n");
        exit(0);
    }    
    srand (time(NULL));
    
    int valorAleatorio;  
    char cad;
    int consulta = 1, deposito = 2, saldo = 0, respuesta = 0;  
    char cadena[1];
    int cont = 0;
    
   for(int i = 0; i < atoi(argv[2]); i++){

       valorAleatorio = 1 + rand() % 10; 
       cout << "\nA depositar: $" << valorAleatorio <<endl;
       
       Solicitud s;

       memcpy(&respuesta, s.doOperation(argv[1], 7200, 1, (char *)&valorAleatorio), 4);
       
       saldo = saldo + valorAleatorio;

        if (saldo != respuesta)
		{
			printf("Saldo actual: $%d\n", respuesta);
			exit(0);
		}

        printf("Saldo actual: $%d\n", respuesta);
    }
    return 0;
}
