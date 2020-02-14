#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;
//                  A           D
Ortoedro::Ortoedro(Coordenada A,Coordenada D)
{ 
    //Cara 1                 A     B
    caras[0].inicializarRec(A,Coordenada(D.obtenerX(),D.obtenerY(),A.obtenerZ()));
    //Cara 2                 C           D
    caras[1].inicializarRec(Coordenada(A.obtenerX(),D.obtenerY(),A.obtenerZ()),D);
    //Cara 3                 E                                                  F
    caras[2].inicializarRec(Coordenada(A.obtenerX(),D.obtenerY(),D.obtenerZ()),Coordenada(D.obtenerX(),A.obtenerY(),D.obtenerZ()));
    //Cara 4                 G                                                  H
    caras[3].inicializarRec(Coordenada(A.obtenerX(),A.obtenerY(),D.obtenerZ()),Coordenada(D.obtenerX(),A.obtenerY(),A.obtenerZ()));
    //Cara 5                 C                                                  G
    caras[4].inicializarRec(Coordenada(A.obtenerX(),D.obtenerY(),A.obtenerZ()),Coordenada(A.obtenerX(),A.obtenerY(),D.obtenerZ()));
    //Cara 6                 D  H
    caras[5].inicializarRec(D,Coordenada(D.obtenerX(),A.obtenerY(),A.obtenerZ()));

    //caras[1].inicializarRec();
}

Ortoedro::Ortoedro(Rectangulo c1,Rectangulo c2,Rectangulo c3,Rectangulo c4,Rectangulo c5,Rectangulo c6)
{
    caras[0] = c1;
    caras[1] = c2;
    caras[2] = c3;
    caras[3] = c4;
    caras[4] = c5;
    caras[5] = c6;
}


void Ortoedro::obtieneVertices()
{
    cout << "Vertice A = [" << caras[0].obtieneSupIzq().obtenerX() << " , " << caras[0].obtieneSupIzq().obtenerY() << " , " <<caras[0].obtieneSupIzq().obtenerZ() << " ]\n";
    cout << "Vertice B = [" << caras[0].obtieneInfDer().obtenerX() << " , " << caras[0].obtieneInfDer().obtenerY() << " , " <<caras[0].obtieneInfDer().obtenerZ() << " ]\n";
    cout << "Vertice C = [" << caras[1].obtieneSupIzq().obtenerX() << " , " << caras[1].obtieneSupIzq().obtenerY() << " , " <<caras[1].obtieneSupIzq().obtenerZ() << " ]\n";
    cout << "Vertice D = [" << caras[1].obtieneInfDer().obtenerX() << " , " << caras[1].obtieneInfDer().obtenerY() << " , " <<caras[1].obtieneInfDer().obtenerZ() << " ]\n";
    cout << "Vertice E = [" << caras[2].obtieneSupIzq().obtenerX() << " , " << caras[2].obtieneSupIzq().obtenerY() << " , " <<caras[2].obtieneSupIzq().obtenerZ() << " ]\n";
    cout << "Vertice F = [" << caras[2].obtieneInfDer().obtenerX() << " , " << caras[2].obtieneInfDer().obtenerY() << " , " <<caras[2].obtieneInfDer().obtenerZ() << " ]\n";
    cout << "Vertice G = [" << caras[3].obtieneSupIzq().obtenerX() << " , " << caras[3].obtieneSupIzq().obtenerY() << " , " <<caras[3].obtieneSupIzq().obtenerZ() << " ]\n";
    cout << "Vertice H = [" << caras[3].obtieneInfDer().obtenerX() << " , " << caras[3].obtieneInfDer().obtenerY() << " , " <<caras[3].obtieneInfDer().obtenerZ() << " ]\n";

}

//Suma de las areas de los Rectangulos
double Ortoedro::obtieneArea()
{
    double areaT = 0;
    double aux = 0;

    for (int i = 0; i <= 5; i++)
    {
        aux = caras[i].obtieneArea();
        if (aux < 0)
            aux = aux * -1;
        //cout << "El area de la cara " << i+1 << " es: " << aux << endl;
        areaT = areaT + aux;
    }

    return areaT;
}

//Multiplicar el area de la base (Cara 1) por la altura que seria Z2 - Z1 de la cara 6
double Ortoedro::obtieneVolumen()
{
    double volumenT = 0;
    volumenT = caras[0].obtieneArea() * (caras[5].obtieneSupIzq().obtenerZ() - caras[5].obtieneInfDer().obtenerZ() );
    return volumenT;
}