#include "Numero.h"
#include <iostream>
using namespace std;

Numero::Numero(int n,bool x) : num(n),esPrimo(x)
{}

void Numero::setNumero(int n)
{
    num = n;
}
void Numero::setBooleano(bool x)
{
    esPrimo = x;
}

int Numero::getNumero()
{
    return num;
}
bool Numero::getBooleano()
{
    return esPrimo;
}