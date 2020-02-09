/*
    H = (g*t^2)/2
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int tiempo=0;
    float altura=0;
    float gravedad = 9.8;

    cout << "Ingrese el tiempo en segundos que tardo en caer la pelota: \n> ";
    cin >> tiempo;

    altura = (gravedad * (pow(tiempo,2)) ) / 2.0;

    cout << "La altura es: " << altura << " metros." << endl;
}