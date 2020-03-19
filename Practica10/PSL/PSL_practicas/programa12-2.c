#include <pthread.h>
#include <stdio.h>
#define MAX_HILOS 10

void funcion(void)
{
   printf("HIlo %d \n", (int) pthread_self());
   pthread_exit(0);
}

int main(void)
{
   int i;
   pthread_attr_t atributos;
   pthread_t thid[MAX_HILOS];
   
   /* Se inicializan los atributos como independientes */
   pthread_attr_init(&atributos);
   pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);
   for(i = 0; i < MAX_HILOS; i++)
      pthread_create(&thid[i], &atributos, (void *)funcion, NULL);
      
   /* El hilo principal se suspende 6 segundos, para esperar a que los hilos hijos terminen. De lo contrario al terminar el
   proceso principal, también todos sus hijos terminarían */
   sleep(6);
}


