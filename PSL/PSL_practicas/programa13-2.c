#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Puerto donde reside nuestro servicio de tiempo */
#define PUERTO 50000
/* Tamaño del buffer de recepción de datos */
#define TAMBUF 32

int main(void) {
   int s, c, n;
   struct sockaddr_in sa;
   char buf[TAMBUF];
   time_t t;
   
   if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket");
      exit(1);
   }
   sa.sin_family = AF_INET;
   sa.sin_port = htons(PUERTO);
   sa.sin_addr.s_addr = htonl(INADDR_ANY);
   if (bind(s, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
      perror("bind");
      exit(1);
   }
   if (listen(s, 5) < 0) {
      perror("listen");
      exit(1);
   }
   do {
      if ((c = accept(s, NULL, 0)) < 0) {
         perror("accept");
         exit(1);
      }
      t = time(NULL);
      n = sprintf(buf, "%s", ctime(&t));
      if (write(c, buf, n) < 0) {
         perror("write");
         exit(1);
      }
      close(c);
   } while(1);
}

