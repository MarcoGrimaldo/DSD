#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

pid_t pid;

int main(int argc, char **argv)
{
   int pid, status;
   /* Se crea el proceso hijo */
   pid = fork();
   switch(pid)
   {
   case -1:
      exit(-1);
   case 0:
   /* El proceso hijo ejecuta el comando solicitado */
   default:
   /* Establece el manejador */
   /* Espera al proceso hijo */
   wait(&status); /* Véase con man para más detalles sobre wait */
   }
   
   exit(0);
}

