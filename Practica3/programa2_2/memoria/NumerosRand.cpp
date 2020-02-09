#include "NumerosRand.h"
#include <unistd.h>
#include <iostream>
using namespace std;

NumerosRand::NumerosRand(unsigned int num)
{
    numeroElementos = num;
    arreglo = new int[numeroElementos];
}

void NumerosRand::inicializaNumerosRand()
{
    unsigned int i;
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = rand();
    return;
}

NumerosRand::~NumerosRand()
{
    delete[] arreglo;
}