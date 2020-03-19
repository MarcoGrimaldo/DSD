#include <stdio.h>
#include <signal.h>

void tratar_alarma(void)
{
   printf("Alarma activada \n");
}

int main(void)
{
   struct sigaction act;
   sigset_t mask;
   
   /* especifica el manejador */
   act.sa_handler = (void *)tratar_alarma; /*funcion a ejecutar */
   act.sa_flags = 0; /* Ninguna accion especifica */
   
   /* Se bloquea la señal 3 SIGQUIT */
   sigemptyset(&mask);
   sigaddset(&mask, SIGQUIT);
   sigprocmask(SIG_SETMASK, &mask, NULL);
   sigaction(SIGALRM, &act, NULL);
   for(;;)
   {
      alarm(3); /* se arma el temporizador */
      pause(); /* se suspende el proceso hasta que se reciba la señal */
   }
}

