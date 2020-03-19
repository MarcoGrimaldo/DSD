#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
   int bytes_enviados, bytes_leidos, i, descriptor_archivo[2];
   char buffer[BUFSIZ + 1];
   pid_t pid;
   if(pipe(descriptor_archivo) == 0){
      pid = fork();
      if (pid == -1) {
         perror("Error al ejecutar fork");
         exit(-1);
      }
      if (pid == 0) { //Proceso hijo
         for(i = 1; i < 27 ; i++){
            memset(buffer, '\0', sizeof(buffer));
            bytes_leidos = read(descriptor_archivo[0], buffer, BUFSIZ);
            printf("El proceso hijo ha leído %d bytes y el contenido es: %s\n", bytes_leidos, buffer);
         }
         exit(0);
      }
      else { //Proceso padre
         for( i = 65; i < 91; i++){
            bytes_enviados = write(descriptor_archivo[1], (char *) &i, sizeof(char));
            printf("El proceso padre ha enviado por la tuberia %d bytes\n", bytes_enviados);
            sleep(1);
         }
      }
   }
   exit(0);
}

