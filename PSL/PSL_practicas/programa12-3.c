/* Este programa muestra la sincronizaciòn en la impresion de dos hilos */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

int i = 10; /* Variable compartida */
sem_t mutex1;
sem_t mutex2;

void Hilo1(void);
void Hilo2(void);

int main(void){
   pthread_t th1, th2;
   
   // Inicializa los semaforos
   sem_init(&mutex1, 0, 1);
   sem_init(&mutex2, 0, 0);
   
   // Crea hilos
   pthread_create(&th1, NULL, (void *)Hilo1, NULL);
   pthread_create(&th2, NULL, (void *)Hilo2, NULL);
   
   // Esperar a que los hilos terminen
   pthread_join(th1, NULL);
   pthread_join(th2, NULL);
   
   exit(0);
}

void Hilo1(void)
{
   while(i > 0) {
      sem_wait(&mutex1);
      printf("Soy el hIlo 1 (%d) y esta es la impresion %d \n", (int) pthread_self(), i--);
      sem_post(&mutex2);
   }
   pthread_exit(0);
}

void Hilo2(void)
{
   while(i > 0) {
      sem_wait(&mutex2);
      printf("Soy el hIlo 2 (%d) y esta es la impresion %d \n", (int) pthread_self(), i--);
      sem_post(&mutex1);
   }
   pthread_exit(0);
}

