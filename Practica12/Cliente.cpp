#include "Solicitud.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

    if(argc <=3){
        cout << "error Modo de uso: <num1> <num2> n\n";
        exit(0);
    }    

    int n = atoi(argv[3]);

    int cont = 0;

    while(cont < n) {
		Solicitud cliente;   
        char argumento1, argumento2;  
        argumento1 = *argv[1];  
        argumento2 = *argv[2];     
        char mensaje[4000]={argumento1,argumento2}; 
        char ip[15] = "192.168.100.60";
        int puerto = 7200;
        int resultado, id = 1;
        memcpy(&resultado, cliente.doOperation(ip, puerto, id, mensaje), sizeof(resultado));
        cout << "La respuesta del servidor es: " << resultado/257 << endl;

        cont++;
	}

    return 0;
}