#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

Ortoedro::Ortoedro(Rectangulo c1,Rectangulo c2,Rectangulo c3,Rectangulo c4,Rectangulo c5,Rectangulo c6)
{
    caras[0] = c1;
    caras[1] = c2;
    caras[2] = c3;
    caras[3] = c4;
    caras[4] = c5;
    caras[5] = c6;
}

Ortoedro::void obtieneVertices()
{
    cout << "Vertice A = (" << caras[0].obtieneIz
}