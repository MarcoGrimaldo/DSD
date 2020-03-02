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
        Coordenada centro;
        double radio;
        double numVertices;
    public:
        void generaVertices();
        double getNumVertices();
        vector<Coordenada> getVertices();
        void generaCentroRadio();
        Asteroide(int x);
        ~Asteroide();
};

#endif