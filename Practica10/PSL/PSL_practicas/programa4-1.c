#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
   pid_t pid;
   int i = 0, estado;
   pid = fork();
   switch(pid) {
       case -1: /* error del fork */
          perror("Error en el fork");
             break;
       case 0: /* proceso hijo */
          printf("Soy el hijo: PID %d; PPID = %d i = %d\n", getpid(), getppid(), ++i);
          exit(0);
            break;
       default: /* proceso padre */             
          printf("Soy el padre: PID %d; PPID = %d i = %d\n", getpid(), getppid(), --i);
          wait(&estado);
   }
}

