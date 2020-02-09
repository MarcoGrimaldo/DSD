#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(Coordenada superiorIzq1, Coordenada inferiorDer1) : superiorIzq(0,0), inferiorDer(0,0)
{
    superiorIzq = superiorIzq1;
    inferiorDer = inferiorDer1;
}
 
Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }
 
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
    return ancho*alto;
}