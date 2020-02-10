#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main( )
{
    cout << "           " << endl;
    cout << "             (E)- - - - - - - -(D)" << endl;
    cout << "             /|                /|" << endl;
    cout << "            / |               / |" << endl;
    cout << "     Y    (C)- - - - - - - -(B) |" << endl;
    cout << "     ^     |  |              |  |" << endl;
    cout << "     |     | (G)- - - - - - -|-(F)" << endl;
    cout << "     |     | /               | /" << endl;
    cout << "     |     |/                |/" << endl;
    cout << "     |    (A)- - - - - - - -(H)" << endl;
    cout << "     |     " << endl;
    cout << "     O ------------> X" << endl;
    cout << "    /" << endl;
    cout << "   /" << endl;
    cout << "  /" << endl;
    cout << " |/" << endl;
    cout << " Z" << endl;

    Coordenada A(3,6,10);
    Coordenada B(8,12,10);
    Coordenada C(3,12,10);
    Coordenada D(8,12,3);
    Coordenada E(3,12,3);
    Coordenada F(8,6,3);
    Coordenada G(3,6,3);
    Coordenada H(8,6,10);

    Rectangulo cara1;
    cara1.inicializarRec(A,B);
    Rectangulo cara2;
    cara2.inicializarRec(C,D);
    Rectangulo cara3;
    cara3.inicializarRec(E,F);
    Rectangulo cara4;
    cara4.inicializarRec(G,H);
    Rectangulo cara5;
    cara5.inicializarRec(C,G);
    Rectangulo cara6;
    cara6.inicializarRec(D,H);

    Ortoedro orto(cara1,cara2,cara3,cara4,cara5,cara6);

    orto.obtieneVertices();

    cout << "La superficie es: " << orto.obtieneArea() << endl;
    cout << "El volumen es: " << orto.obtieneVolumen() << endl;

    return 0;
} 