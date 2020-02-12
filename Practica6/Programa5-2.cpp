#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
#include <time.h> 
using namespace std;

int main()
{
    vector<PoligonoIrreg> poligonos;
    int n; //Poligonos
    int m; //de m vertices

    n = 50000; m = 10000;

    //poligonos.reserve(n);

    for (int i = 0; i < n; i++)
    {
        PoligonoIrreg p_ir;
        /* m vertices en cada poligono (Aleatorio hasta m) */
        int ver_ran = rand() % m + 3;
        //p_ir.reserveVer(ver_ran);

        for (int j = 0; j < ver_ran ; j++)
        {
            p_ir.anadeVertices(Coordenada(rand() % 10,rand() % 10));
        }

        poligonos.push_back(p_ir);
    }

    cout << "Vertices creados: " << poligonos[0].getVecesMuestF() << endl;
    return 0;
}