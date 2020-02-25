#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include "Coordenada.h"
#include <unistd.h>
#include <vector>
using namespace std;

class Asteroide
{
    private:
        vector<Coordenada> vertices;
        int numVertices;
    public:
        void generaVertices(int n);
        vector<Coordenada> getVertices();
        Asteroide(int x);
        ~Asteroide();
};

#endif