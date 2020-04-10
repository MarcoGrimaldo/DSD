// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <math.h>
  
#define PORT     7200 
#define MAXLINE 1024 

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
  
// Driver code 
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in     servaddr; 

    double array[785];

    for (int i = 0; i <= 784; i++)
    {
        array[i] = fourierSerie(3,deToRad(i));
    }
    

    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 

    sendto(sockfd, array, sizeof(array), 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
    printf("Hello message sent.\n"); 
          
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr *) &servaddr, 
                &len); 
    buffer[n] = '\0'; 
    printf("Server : %s\n", buffer); 
  
    close(sockfd); 
    return 0; 
} 