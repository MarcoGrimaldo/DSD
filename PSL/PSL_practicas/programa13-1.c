#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <unistd.h>
#include <stdlib.h>

/* Direccion IP del servidor de tiempo */
#define HOST "127.0.0.1"
/* Puerto donde reside el servicio */
#define PUERTO 50000
/* Tamaño del buffer de recepcion de datos */
#define TAMBUF 32

int main(void) {
   int s, n;
   struct sockaddr_in sa;
   char buf[TAMBUF];
   
   if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket");
      exit(1);
   }
   sa.sin_family = AF_INET;
   sa.sin_port = htons(PUERTO);
   if (!inet_aton(HOST, &sa.sin_addr)) {
      perror("inet_aton");
      exit(1);
   }
   if (connect(s, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
      perror("connect");
      exit(1);
   }
   if ((n = read(s, buf, TAMBUF)) < 0) {
      perror("read");
      exit(1);
   }
   close(s);
   write(STDOUT_FILENO, buf, n);
   
   exit(0);
}

