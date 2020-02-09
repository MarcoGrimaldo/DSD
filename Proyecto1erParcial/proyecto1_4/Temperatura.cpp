#include "Temperatura.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Temperatura::Temperatura()
{
    tmpKelvin = 0;
}

void Temperatura::setTempKelvin(int tmp)
{
    tmpKelvin = tmp;
}

void Temperatura::setTempFahrenheit(int tmp)
{
    tmpKelvin = (tmp - 32.0) * (5.0/9.0) + 273.0;
}

void Temperatura::setTempCelsius(int tmp)
{
    tmpKelvin = tmp + 273.0;
}

float Temperatura::getTempKelvin()
{
    return tmpKelvin;
}

float Temperatura::getTempFahrenheit()
{
    return ((tmpKelvin-273.0)*(9.0/5.0)+32);
}

float Temperatura::getTempCelsius()
{
    return (tmpKelvin - 273.0);
}