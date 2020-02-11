#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
using namespace std;

int PoligonoIrreg::vecesMuestF = 0;

int PoligonoIrreg::getVecesMuestF()
{
    return vecesMuestF;
}

PoligonoIrreg::PoligonoIrreg()
{ }

void PoligonoIrreg::anadeVertices(Coordenada v)
{
    vertices.push_back(v);
    vecesMuestF++;
}

void PoligonoIrreg::imprimeVertices()
{
    for (int i = 0; i < vertices.size() ; i++)
    {
        cout << "Vertice " << i+1 << " : " << vertices[i].obtenerX() << " , " << vertices[i].obtenerY() << endl;
    }
    
}

vector<Coordenada> PoligonoIrreg::getVertices()
{
    return vertices;
}

PoligonoIrreg::~PoligonoIrreg()
{
}