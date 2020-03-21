#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
using namespace std;

int main(){
    SocketDatagrama server = SocketDatagrama(7200);
    cout << "Server iniciado" << endl;

    while(1) {
        PaqueteDatagrama paquete = PaqueteDatagrama(65507);

        if(server.recibe(paquete)) {
        	cout << "\nMensaje recibido de:" << endl;
        	cout << "IP: " << paquete.obtieneDireccion() << endl;
        	cout << "Puerto: " << paquete.obtienePuerto() << endl;
        	cout << "Datos: " << paquete.obtieneDatos() << endl;
        	cout << "Longitud: " << paquete.obtieneLongitud() << endl;
        }
    }
}