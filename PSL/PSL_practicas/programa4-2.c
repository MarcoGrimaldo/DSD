#include <sys/types.h>
#include <stdio.h>

main()
{
   pid_t pid;
   int j;
   for(j = 0; j < 10; j++){
       pid = fork();
       if(pid != 0)
          break;
   }
   printf("El padre del proceso %d es %d, j = %d\n", getpid(), getppid(), j);
   sleep(3);
}

