// Client side implementation of UDP client-server model 
// g++ -std=c++11 hilos1.cpp -o hilos1 -lpthread

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

#define PORT     7200 
#define MAXLINE 1024 

std::mutex m;

double deToRad(int num)
{
    return (num / 100.0) *  3.1416/1.96;
}

double fourierSerie(int n,double t)
{
        double result = 0;
        for(int i = 0; i <= n ; i++)
        {
            result = result + sin(t * ((2*i) + 1) ) / ((2*i) + 1);
        }
        
        return result;
}
  
void creaYEnviaCordenadas(int n,double bandera)
{
    m.lock();
    int sockfd;
    char buffer[MAXLINE]; 
    struct sockaddr_in     servaddr; 

    double array[786];

    //El primer dato es una bandera
    array[0] = bandera;

    //Creamos las coordenadas para Y, con la serie de fourier y de acuerdo a n
    for (int i = 1; i <= 785; i++)
    {
        array[i] = fourierSerie(n,deToRad(i));
    }

    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
        { 
            perror("socket creation failed"); 
            exit(EXIT_FAILURE); 
        } 
    
        memset(&servaddr, 0, sizeof(servaddr)); 
        
        // Filling server information 
        servaddr.sin_family = AF_INET; 
        servaddr.sin_port = htons(PORT); 
        servaddr.sin_addr.s_addr = INADDR_ANY; 
        
        int len; 

        sendto(sockfd, array, sizeof(array), 
            MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
                sizeof(servaddr)); 
        printf("Coodenadas enviadas.N = %i | BORRA = %lf\n",n,bandera);

        //usleep(8000);
        //La espera cambia de a cuerdo si se va  dibujar o a borrar
        if (bandera == 0.0)
        {
            usleep(10000);
        }
        else
        {
            usleep(8000);
        }
        
        //sleep(1);

        close(sockfd); 
    m.unlock();

}

// Driver code 
int main() { 
    int n = 0;
    
    for (int i = 0; i < 350; i++)
    {
        std::thread th1(creaYEnviaCordenadas,n,0.0), th2(creaYEnviaCordenadas,n,1.0);
        th1.join();
        th2.join();
        //Vamos a ir aumentando n
        n = i;
    }

    return 0; 
} 