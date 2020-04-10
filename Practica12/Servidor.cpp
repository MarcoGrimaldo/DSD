#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include "Respuesta.h"
using namespace std;

int main(int argc, char *argv[]){
    Respuesta respuesta(7200);
    while(true){
        char *resMsg;
        int num1, num2;
        int id, resultado;
        cout << "Esperando a cliente..." << endl;
        struct mensaje *msg = respuesta.getRequest();
        char argumento_recibido[50];

        memcpy(argumento_recibido, msg->arguments, 2 * sizeof(char));
        cout << "El argumento recibido es: " << argumento_recibido[0] << " Y " << argumento_recibido[1] << endl;

        id = msg->operationId;
        num1 = (int) argumento_recibido[0] - 48;
        num2 = (int) argumento_recibido[1] - 48;
    
        if(id == 1)
            resultado = num1 + num2;
        else
            resultado = num1 - num2;

        cout << "El resultado es: " << resultado << endl;
        char aux = (char) resultado;        
        resMsg = &aux;
        //sprintf(resMsg, "%d", resultado);       
        respuesta.sendReply(resMsg, msg->IP, msg->puerto);
    }
}
