#ifndef MEMORIA_H_
#define MEMORIA_H_

class NumerosRand
{
    private:
        int *arreglo;
        unsigned int numeroElementos;
    public:
        NumerosRand(unsigned int num);
        void inicializaNumerosRand(void);
        ~NumerosRand();
};
#endif