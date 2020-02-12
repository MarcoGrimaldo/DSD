#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int PoligonoIrreg::vecesMuestF = 0;

int PoligonoIrreg::getVecesMuestF()
{
    return vecesMuestF;
}

PoligonoIrreg::PoligonoIrreg(int n)
{
    vertices.reserve(n);
}

void PoligonoIrreg::reserveVer(int x)
{
    vertices.reserve(x);
}

void PoligonoIrreg::anadeVertices(Coordenada v)
{
    vertices.push_back(v);
    vecesMuestF++;
}

void PoligonoIrreg::imprimeVertices()
{
    std::vector<Coordenada>::iterator i;
    int j=0;
    for ( i = vertices.begin(); i != vertices.end(); i++,j++)
    {
        Coordenada co_a = *i;
        cout << "Vertice " << j+1 << " : " << co_a.obtenerX() << " , " << co_a.obtenerY() << endl;
        double mag = sqrt( pow(co_a.obtenerX(),2.0) + pow(co_a.obtenerY(),2.0));
        cout << "Magnitud: " << mag << endl;
    }
}

vector<Coordenada> PoligonoIrreg::getVertices()
{
    return vertices;
}

PoligonoIrreg::~PoligonoIrreg()
{
}