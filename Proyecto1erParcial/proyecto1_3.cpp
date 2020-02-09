/*
    Hora = 60 minutos = 3600 segundos
    Minuto = 60 segundos
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int numero;
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    cout << "Ingrese el valor entero en segundos: ";
    cin >> numero;

    if(numero >= 3600.0)
    {
        horas = numero  / 3600.0;
        cout << horas << " horas, ";
    }
    if (numero >= 60.0)
    {
        minutos =  (numero / 60) - (horas * 60.0);
        cout << minutos << " minutos, ";
    }

    segundos = numero - (minutos * 60) - (horas * 3600);
    cout << segundos << " segundos.";
    
}