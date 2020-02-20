#ifndef _NUMERO_H_
#define _NUMERO_H_

class Numero
{
    private:
        int num;
        bool esPrimo;
    public:
        Numero(int n,bool x);
        void setNumero(int n);
        void setBooleano(bool x);
        int getNumero();
        bool getBooleano();
};

#endif