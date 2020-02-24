#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;

char buffer[BUFSIZ];

int main(int argc, char *argv[]){
    int destino;
    string linea;
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
        exit(0);
    }
    cout << "Introduce texto para guardar en el archivo y ENTER para terminar. Longitud máxima de caracteres = " << BUFSIZ << endl;
    getline(cin, linea);
    strcpy(buffer, linea.c_str( ));
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    write(destino, buffer, strlen(buffer));
    fsync(destino);
    close(destino);
}