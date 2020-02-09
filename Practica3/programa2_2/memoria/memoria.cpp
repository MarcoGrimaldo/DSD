#include "NumerosRand.h"
#include <unistd.h>
#include <iostream>
using namespace std;

void pruebaClase()
{
    unsigned int capacidad;
    cout << "Numero de enteros aleatorios en el arreglo : ";
    cin >> capacidad;
    NumerosRand tmp(capacidad);
    tmp.inicializaNumerosRand();
    sleep(7); 
}

int main()
{
    char res;
    do{
        pruebaClase();
        pruebaClase();
        cout << "Probar de nuevo? (s/n) ";
        cin >> res;
    }while ((res == 's') || (res == 'S'));
    
}