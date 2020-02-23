#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

int var = 0;

void incremento() 
{
    var += 1;
    printf("Hilo %ld incremento, Valor: %d\n", this_thread::get_id(), var);
    sleep(1);
}

void decremento() 
{
    var -= 1;
    printf("Hilo %ld decremento, Valor: %d\n", this_thread::get_id(), var);
    sleep(1);
}

int main() {
    thread th1(incremento), th2(decremento);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    printf("var: %d\n", var);
    exit(0);
}