#include "SocketMulticast.h"

int main(int argc, char *argv[])
{
    if(argc!= 3){
        cout << "Error: MODO de uso <IP> <Puerto> " << endl;
        exit(1);
    }

    char* IP = argv[1];
    int puerto = atoi(argv[2]);

    SocketMulticast sm = SocketMulticast(3030);
    PaqueteDatagrama p = PaqueteDatagrama(sizeof(struct mensaje*));
    sm.unirseGrupo(IP);
    cout << "Esperando...\n";

    int nbd[1];
    nbd[0] = 0;

    SocketDatagrama s = SocketDatagrama(0);
    while (true) {
        if(sm.recibeConfiable(p) != -1) {
            int n = 0;
            memcpy(&n, p.obtieneDatos(), 4);
            nbd[0] = nbd[0] + n;
            printf("Recibido: %d |", n);
            printf("NBD: %d\n",nbd[0]);
            
            PaqueteDatagrama respuesta = PaqueteDatagrama(4);
            respuesta.inicializaIp(p.obtieneDireccion());
            respuesta.inicializaDatos(p.obtieneDatos());
            respuesta.inicializaPuerto(7200);
            s.envia(respuesta);     
		}
    }
}