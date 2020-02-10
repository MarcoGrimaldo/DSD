#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion()
{
    numerador = 1;
    denominador = 1;
}

int Fraccion::get_numerador()
{
    return numerador;
}

int Fraccion::get_denominador()
{
    return denominador;
}

void Fraccion::inicializaFraccion(int num, int den)
{
    numerador = num;
    denominador = den;
}

double Fraccion::division()
{
    return static_cast<double>(numerador) / static_cast<double>(denominador);
}

Fraccion Fraccion::min_exp()
{
    int new_num,new_den,m;
    int mcd = 0;
    Fraccion new_frac;

    if( numerador < denominador)
        m = numerador;
    else
        m = denominador;
    
    //Se obtiene el maximo comun divisor
    for (int i = 2; i <= m; i++)
    {
        if(numerador % i == 0 && denominador % i == 0)
        {
            mcd = i;
        }
    }

    if(mcd != 0)
    {
        new_num = numerador / mcd;
        new_den = denominador / mcd;

        new_frac.inicializaFraccion(new_num,new_den);

        return new_frac;
    }
    else
    {
        cout << "La fraccion ya esta a su minima expresion\n";
        new_frac.inicializaFraccion(numerador,denominador);
        return new_frac;
    }

}

