#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <cstring>
using namespace std;

string randomString() 
{
	string alfabeto("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string palabra = "";

	for(int i = 0; i < 3; i++) 
    {
		int ra = rand() % 25;
		palabra.insert(i, 1, alfabeto.at(ra));
	}
	palabra.insert(3, 1, ' ');
	return palabra;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int n = 1757600;

	int destino;
	string linea = "";

	if(argc != 2)
    {
		cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
		exit(0);
	}
	
    for (int i = 0; i < n; i++)
    	linea.insert(4 * i, randomString());

	
	if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    {
		perror(argv[1]);
		exit(-1);
	}

	int i = 1;
	int j = 0;
	int cont = 0;
	char candenota[7030401];
	strcpy(candenota,linea.c_str());

	while (i <= 7030400) 
    {
		char buffer[BUFSIZ];
		buffer[j] = candenota[i-1];

		if(i % BUFSIZ == 0 )
		{			
			write(destino,buffer,BUFSIZ);
			j = 0;
			cont++;
		}
		if (i == 7030400)
			write(destino,buffer,7030400-(cont*BUFSIZ));
		
		else
			j++;
		i++;  
    }

	fsync(destino);
	close(destino);

}