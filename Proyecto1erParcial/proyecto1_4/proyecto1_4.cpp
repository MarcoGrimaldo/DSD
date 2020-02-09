#include "Temperatura.h"
#include <iostream>
using namespace std;

int main()
{
    char opTemp = 0;
    int temp = 0;

    cout << "Ingrese temperatura: ";
    cin >> temp;

    cout << "Seleccione escala: \n\n [K] Kelvin \n [F] Fahrenheit\n [C] Celsius \n\n>> ";
    cin >> opTemp;

    Temperatura tp;

    if(opTemp == 'K' || opTemp == 'k')
    {
        tp.setTempKelvin(temp);
    }

    if(opTemp == 'F' || opTemp == 'f')
    {  
        tp.setTempFahrenheit(temp);
    }
    if(opTemp == 'C' || opTemp == 'c')
    {
        tp.setTempCelsius(temp);
    }

    cout << "Temperatura ingresada: " << tp.getTempKelvin() << " K\n";
    cout << "Temperatura en Fahrenheit: " << tp.getTempFahrenheit() << " F\n";
    cout << "Temperatura en Celsius: " << tp.getTempCelsius() << " C\n";
}