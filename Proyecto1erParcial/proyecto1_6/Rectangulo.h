#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo 
{
    private:
        Coordenada superiorIzq;
        Coordenada inferiorDer; 
    public:
        Rectangulo();
        void inicializarRec(Coordenada superiorIzq, Coordenada inferiorDer);
        void imprimeEsq();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
        double obtieneArea();
};

#endif