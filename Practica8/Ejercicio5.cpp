#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic> 
using namespace std;

//int global = 0;

void incremento(atomic<int> &global) 
{
    for (int i = 0; i < 10; i++)
    {
        global += 1;
        //"Hilo %ld incremento, Valor: %d\n", this_thread::get_id(), global);
        cout << "Hilo " << this_thread::get_id() << " incremento, Valor: " << global << endl;
        sleep(1);
    }
    
}

void decremento(atomic<int> &global) 
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
    atomic <int> global(0); 
    thread th1(incremento,ref(global)), th2(decremento,ref(global));
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    //printf("global: %d\n", global);
    cout << "global: " << global << endl;
    exit(0);
}