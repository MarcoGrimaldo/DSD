#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion
{
    private:
        int numerador;
        int denominador;
    public:
        Fraccion();
        void inicializaFraccion(int num, int den);
        double division();
        Fraccion min_exp();
        int get_numerador();
        int get_denominador();
};

#endif