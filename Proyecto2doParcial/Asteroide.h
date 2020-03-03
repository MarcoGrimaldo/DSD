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
        int anguloDireccion;
        double alpha,beta,j;
    public:
        Asteroide(int x);
        void generaVertices();
        double getNumVertices();
        vector<Coordenada> getVertices();
        void inicializaAsteoriode();
        void setVertices(Coordenada newC,int at);
        Coordenada getCoordenadaVertice(int at);
        void mueveAsteroide();
        void giraAsteroide();
        ~Asteroide();
};

#endif