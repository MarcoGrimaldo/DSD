#include "Fraccion.h"
#include <iostream>
using namespace std;

int main()
{
    int num_in, den_in;
    
    cout << "Introduzca el numerador: ";
    cin >> num_in;
    cout << "Introduzca el denominador: ";
    cin >> den_in;

    Fraccion frac;

    //Inicializa la fraccion
    frac.inicializaFraccion(num_in,den_in);
    //muestra la fraccion
    cout << "La fraccion es: " << frac.get_numerador() << " / " << frac.get_denominador() << endl;
    //muestra la division
    cout << "El resultado es: " << frac.division() << endl;
    //minima expresion
    Fraccion n_frac = frac.min_exp();
    cout << "La minima expresion es: " << n_frac.get_numerador() << " / " << n_frac.get_denominador() << endl;
}