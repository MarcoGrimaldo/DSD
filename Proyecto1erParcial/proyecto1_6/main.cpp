#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main( )
{
    cout << "           " << endl;
    cout << "             (E)- - - - - - - ((D))" << endl;
    cout << "             /|                /|" << endl;
    cout << "            / |               / |" << endl;
    cout << "     Y    (C)- - - - - - - -(B) |" << endl;
    cout << "     ^     |  |              |  |" << endl;
    cout << "     |     | (G)- - - - - - -|-(F)" << endl;
    cout << "     |     | /               | /" << endl;
    cout << "     |     |/                |/" << endl;
    cout << "     |   ((A)) - - - - - - -(H)" << endl;
    cout << "     |     " << endl;
    cout << "     O ------------> X" << endl;
    cout << "    /" << endl;
    cout << "   /" << endl;
    cout << "  /" << endl;
    cout << " |/" << endl;
    cout << " Z\n" << endl;

    Coordenada A(3,6,10);
    Coordenada D(8,12,3);

    Ortoedro orto(A,D);

    orto.obtieneVertices();

    cout << "\nLa superficie es: " << orto.obtieneArea() << endl;
    cout << "El volumen es: " << orto.obtieneVolumen() << endl;

    return 0;
} 