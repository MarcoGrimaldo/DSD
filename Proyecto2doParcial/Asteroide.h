#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include "Coordenada.h"
#include <unistd.h>
#include <vector>
using namespace std;

class Asteroide
{
    private:
        vector<Coordenada> lados;
    public:
        void generaLados();
        Asteroide();
        ~Asteroide();
};

#endif