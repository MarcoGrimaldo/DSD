#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic> 
using namespace std;

//int global = 0;
atomic <int> global(0); 

void incremento() 
{
    for (int i = 0; i < 10; i++)
    {
        global += 1;
        //"Hilo %ld incremento, Valor: %d\n", this_thread::get_id(), global);
        cout << "Hilo " << this_thread::get_id() << " incremento, Valor: " << global << endl;
        sleep(1);
    }
    
}

void decremento() 
{
    for (int i = 0; i < 10; i++)
    {
        global -= 1;
        //printf("Hilo %ld decremento, Valor: %d\n", this_thread::get_id(), global);
        cout << "Hilo " << this_thread::get_id() << " decremento, Valor: " << global << endl;

        sleep(1);
    }
}

int main() 
{
    thread th1(incremento), th2(decremento);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    //printf("global: %d\n", global);
    cout << "global: " << global << endl;
    exit(0);
}