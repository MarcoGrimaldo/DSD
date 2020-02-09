#include <iostream>
using namespace std;

int main()
{
    double tempC;
    double tempF;
    cout << "Introduzca la temperatura: ";
    cin >> tempC;

    tempF = (1.8 * tempC) + 32.0;

    cout << "Trampa-> F: " << tempF << endl;

    tempF = (static_cast<double>(9.0/5.0)) * tempC +32.0;

    cout << "Cast -> F: " << tempF << endl;
    

     return 0;

}