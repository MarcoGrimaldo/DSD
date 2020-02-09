#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) {
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
    mes = mm;
    dia = dd;
    anio = aaaa;
    return;
}

void Fecha::muestraFecha() {
    cout << "La fecha es(dia-mes-anio): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAnio()
{
    return anio;
}

void Fecha::setDia(int d)
{
    dia = d;
}

void Fecha::setMes(int m)
{
    mes = m;
}

void Fecha::setAnio(int a)
{
    anio = a;
}

int Fecha::convierte() {
    int FechaConv = (anio * 10000) + (mes * 100) +dia;
    return FechaConv;
}

bool Fecha::leapyr() {
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        return true;
    else
        return false;
}
