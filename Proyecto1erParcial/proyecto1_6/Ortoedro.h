#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Coordenada.h"
#include "Rectangulo.h"

class Ortoedro
{
    private:
        Rectangulo caras[5];
    public:
        Coordenada obtieneVertices();
        double obtieneArea();
        double obtieneVolumen();
};

#endif