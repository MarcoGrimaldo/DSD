#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo()
{}
 
void Rectangulo::inicializarRec(Coordenada superiorIzq1, Coordenada inferiorDer1)
{
    superiorIzq = superiorIzq1;
    inferiorDer = inferiorDer1;
}

void Rectangulo::imprimeEsq()
{
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n"; 
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;  
}

Coordenada Rectangulo::obtieneSupIzq()
{
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer()
{
    return inferiorDer;
}

double Rectangulo::obtieneArea()
{
    double ancho, alto;

    alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
    ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();

    if(alto == 0)
        alto = superiorIzq.obtenerZ() - inferiorDer.obtenerZ();
    if(ancho == 0)
        ancho = superiorIzq.obtenerZ() - inferiorDer.obtenerZ();

    return ancho*alto;
}