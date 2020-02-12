#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>
using namespace std;

class PoligonoIrreg
{
    private:
        vector<Coordenada> vertices;
        static int vecesMuestF;
    public:
        static int getVecesMuestF();
        PoligonoIrreg(int n);
        void anadeVertices(Coordenada v);
        void imprimeVertices();
        vector<Coordenada> getVertices();
        void reserveVer(int x);
        ~PoligonoIrreg();
};


#endif