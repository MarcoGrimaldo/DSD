#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void funcion(void)
{
   printf("Hilo %d \n", (int) pthread_self());
   sleep(2);
   pthread_exit(0);
}

int main(void)
{
   pthread_t th1, th2;
   
   /* Se crean dos hilos con atributos predeterminados */
   pthread_create(&th1, NULL, (void *)funcion, NULL);
   pthread_create(&th2, NULL, (void *)funcion, NULL);
   printf("El hilo principal espera a sus hijos\n");
   
   /* se espera su terminación */
   pthread_join(th1, NULL);
   pthread_join(th2, NULL);
   printf("El hilo principal termina\n");
   
   exit(0);
}

