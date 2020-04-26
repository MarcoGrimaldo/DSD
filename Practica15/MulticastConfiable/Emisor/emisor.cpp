#include "SocketMulticast.h"

int main(int argc, char* argv[])
{

	if(argc!= 6){
        cout << "Error: MODO de uso <IP> <Puerto> <TTL> <Numero de veces> <Numero de receptores>" << endl;
        exit(1);
    }
    
    char* IP = argv[1];
    int puerto = atoi(argv[2]);
    int TTL = atoi(argv[3]);
    int n = atoi(argv[4]);
    int num_receptores = atoi(argv[5]);

	srand(time(NULL));
	
	int cont = 0;
	int cuenta = 0;

	SocketDatagrama s = SocketDatagrama(puerto);
	SocketMulticast sm = SocketMulticast(0);

	while (cont < n)
	{
		int arr = 1 + rand() % 9;
		cuenta = cuenta + arr;
    	PaqueteDatagrama p = PaqueteDatagrama((char*)&arr, sizeof(struct mensaje), IP, 3030);
    	int enviar = sm.enviaConfiable(p, TTL, num_receptores);
    	int intentos = 1;

		while(enviar < 0 && intentos < 7) {
			cout << "Reintentando..." << endl;
			enviar = sm.enviaConfiable(p, TTL, num_receptores);
			intentos++;
		}

		if(intentos == 7){
			cout << "Algun receptor no da respuesta :(" << endl;
			exit(0);
		}
		
		printf("A depositar: %d\nSaldo: %d\n", arr, cuenta);
		
		int cont2 = 0;
		while(cont2 < num_receptores) {
			PaqueteDatagrama respuesta = PaqueteDatagrama(4);
	        s.recibeTimeout(respuesta, 5, 500);
	        int res = 0;
	        memcpy(&res, respuesta.obtieneDatos(), 4);
			printf("Respuesta del receptor %d: %d | IP:", cont2 + 1,res);
			cout<< respuesta.obtieneDireccion()<<endl;
			cont2++;
		}
	    cont++;
	}
	return 0;
}