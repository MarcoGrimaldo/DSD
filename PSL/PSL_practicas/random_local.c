/* Programa random_local.c que incluye unicamente el programa main */
#include "random_local.h"

int main(int argc, char *argv[])
{
   int misemilla, itera, i;
   
   if(argc != 3) {
      fprintf(stderr, "Uso: %s semilla iteraciones\n", argv[0]);
      exit(1);
   }
   misemilla = (long)atoi(argv[1]);
   itera = atoi(argv[2]);
   inicializa_random(misemilla);
   for(i = 0; i < itera; i++)
      printf("%d : %d\n", i, (int) obtiene_siguiente_random());
      
   exit(0);
}

