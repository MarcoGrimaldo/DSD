#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
#include <time.h> 
using namespace std;

double aleatorio()
{
    double ent = -100 + ( rand() % ( 100 + 100 + 1 ) );
    double dec = (rand() % (1000)) / 1000.0;

    return ent + dec;
}

int main()
{
    int n; //Vertices
    srand( unsigned(time(NULL) ));

    n = 5;

    PoligonoIrreg poligono_m(n);

    for ( int i = 0; i < n; i++)
    {
        poligono_m.anadeVertices(Coordenada(aleatorio(),aleatorio()));
    }

    poligono_m.imprimeVertices();
    poligono_m.ordenaA();
    cout << "\n ### Ordenados: \n";
    poligono_m.imprimeVertices();

    return 0;
}
