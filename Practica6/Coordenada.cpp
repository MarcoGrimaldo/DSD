#include "Coordenada.h"
#include <iostream>
#include <math.h>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) 
{ }

double Coordenada::obtenerX()
{ 
    return x;
} 
double Coordenada::obtenerY()
{
     return y;
}
double Coordenada::obtenerMagnitud()
{
    return sqrt( pow(x,2.0) + pow(y,2.0));
}