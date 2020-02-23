#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;

int var = 0;
mutex m;

void incremento() 
{
    m.lock();
    for (int i = 0; i < 10; i++)
    {
        var += 1;
        printf("Hilo %ld incremento, Valor: %d\n", this_thread::get_id(), var);
        sleep(1);
    }
    m.unlock();
    
}

void decremento() 
{
    m.lock();
    for (int i = 0; i < 10; i++)
    {
        var -= 1;
        printf("Hilo %ld decremento, Valor: %d\n", this_thread::get_id(), var);
        sleep(1);
    }
    m.unlock();
}

int main() {
    thread th1(decremento), th2(incremento);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    printf("var: %d\n", var);
    exit(0);
}