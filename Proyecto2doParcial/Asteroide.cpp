#include "Coordenada.h"
#include "Asteroide.h"
#include <unistd.h>
#include <vector>
#include <stdlib.h>   
#include <iostream>
using namespace std;

Asteroide::Asteroide(int x) : numVertices(x)
{

}

void Asteroide::generaVertices(int n)
{
    //  Inicialmente obtenemos 2 numeros random
    int CoX, CoY;
    CoX = rand() % 5 + 1;
    CoY = rand() % 5 + 1;

    //  Lo metemos como primera cordenada/vertice de nuestro asteroide
    vertices.push_back(Coordenada(CoX,CoY));

    //  Para n vertices meteremos numeros random
    for (int i = 0; i < n; i++)
    {
        //  Se toman numeros random de -10 a 10
        int sumX, sumY;
        CoX = rand() % 5 - 2;
        CoY = rand() % 5 - 2;

        //  Se suman con el anterior vertice insertado
        sumX = vertices.at(i).obtenerX() + CoX;
        sumY = vertices.at(i).obtenerY() + CoY;

        //  Se ingresan
        vertices.push_back(Coordenada(sumX,sumY));
        cout << "[ " << sumX << " , " << sumY << " ]\n";
    }
    
}

vector<Coordenada> Asteroide::getVertices()
{
    return vertices;
}

Asteroide::~Asteroide()
{

}