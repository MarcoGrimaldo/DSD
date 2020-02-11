#include "Fecha.h"
#include <stdlib.h>
#include <iostream>  
using namespace std;

int Fecha::vecesMuestF = 0;

int Fecha::getVecesMuestF()
{
    return vecesMuestF; 
}

Fecha::Fecha(int dd, int mm, int aaaa)
{
    mes = mm;
    dia = dd;
    anio = aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}
void Fecha::muestraFecha()
{
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    vecesMuestF++;
    return;
}