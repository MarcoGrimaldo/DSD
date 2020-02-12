#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <algorithm>
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
        double mag = co_a.obtenerMagnitud();
        cout << "Magnitud: " << mag << endl;
    }
}

vector<Coordenada> PoligonoIrreg::getVertices()
{
    return vertices;
}

//bool myfunction (Coordenada &i,Coordenada &j) { return (i.obtenerMagnitud() < j.obtenerMagnitud()); }

/*struct myclass {
  bool operator() (Coordenada i,Coordenada j) { return (i.obtenerMagnitud() < j.obtenerMagnitud());}
} myobject;*/

void PoligonoIrreg::ordenaA()
{
    //std::sort(vertices.begin(), vertices.begin(),myfunction);  
    sort(vertices.begin(), vertices.end(), [](Coordenada &i, Coordenada &j) {
        return i.obtenerMagnitud() < j.obtenerMagnitud();
    });
}

PoligonoIrreg::~PoligonoIrreg()
{
}