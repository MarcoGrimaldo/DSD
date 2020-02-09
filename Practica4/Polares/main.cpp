#include "Rectangulo.h"
#include "Coordenada.h"
#include <math.h>
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;

int main( )
{
    Rectangulo rectangulo1(Coordenada(sqrt(13.0),atan(3.0/2.0)),Coordenada(sqrt(26.0),atan(1.0/5.0)));
    double ancho, alto;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();
    cout << "El área del rectángulo es = " <<  rectangulo1.obtieneArea() << endl;
   
    return 0;
} 