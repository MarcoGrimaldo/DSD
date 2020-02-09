#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Coordenada.h"
#include "Rectangulo.h"

class Ortoedro
{
    private:
        Rectangulo caras[5];
    public:
        Ortoedro(Rectangulo c1,Rectangulo c2,Rectangulo c3,Rectangulo c4,Rectangulo c7,Rectangulo c6);
        void obtieneVertices();
        double obtieneArea();
        double obtieneVolumen();
};

#endif