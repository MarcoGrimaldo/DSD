#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int tokens;
   for(tokens = 0; tokens < argc; tokens++) {
      if(argv[tokens][0] == '-')
         printf("opción: %s\n", argv[tokens]+1);
      else
         printf("argumento %d: %s\n", tokens, argv[tokens]);
    }
    exit(0);
}

