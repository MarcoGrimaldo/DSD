#include <stdlib.h>
#include <stdio.h>
extern char **environ;
int main(int argc, char *argv[])
{
   int j;
   printf("Las variables de entorno para %s son\n", argv[0]);
   for(j=0; environ[j] != NULL; j++)
      printf("environ[%d] = %s\n", j, environ[j]);
   return 0;
}

