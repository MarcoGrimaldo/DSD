#include "Coordenada.h"
#include <math.h>
#include <iostream>
using namespace std;

Coordenada::Coordenada(double r, double t)
{     
    x = r * cos(t);
    y = r * sin(t);
}

double Coordenada::obtenerX()
{ 
    return x;
} 
double Coordenada::obtenerY()
{
     return y;
}