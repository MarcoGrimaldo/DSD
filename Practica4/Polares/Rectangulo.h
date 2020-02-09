#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo 
{
    private:
        Coordenada superiorIzq;
        Coordenada inferiorDer; 
    public:
        Rectangulo(Coordenada superiorIzq, Coordenada inferiorDer);
        Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
        void imprimeEsq();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
        double obtieneArea();
};

#endif