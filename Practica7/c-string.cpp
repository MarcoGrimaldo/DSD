#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* stringAleatorio() {
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char string[3];

	for(int i = 0; i < 3; i++) {
		int rand_l = rand() % 25;
		string[i] = letras[rand_l];
	}
	string[3] = ' ';

    static char prueba[] = "IPN ";

	return string;
}

int buscaIPN(char *cadenota)
{
    int con = 0;



    /*for (int i = 0; i < strlen(cadenota); i++)
    {
        if (i != strlen(cadenota)-4)
        {
            if (cadenota[i] == 'I')
            {
                //cout << "Encontre I en " << i << endl; 
                if (cadenota[i+1] == 'P')
                {
                  //  cout << "Encontre P en "<< i+1 << endl;
                    if (cadenota[i+2] == 'N')
                    {
                      //  cout << "Encontre N en " << i+2 << endl;
                        con++;
                    }                        
                }
            }
        }
    }*/

    return con;
}

int main()
{
    char *cadenota = NULL;
    int n = 0; 
    int cont = 0;

    srand(time(NULL));

    printf("Teclea n: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++)
    {
    	char* aux = stringAleatorio();
        cadenota = (char*)realloc(cadenota, (i + 1) * 4);
		memcpy(cadenota + (4 * i), aux, 4);
    }

    printf("\n%d\n",buscaIPN(cadenota));

    return 0;
}