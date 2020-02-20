#include "Numero.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<Numero> Criba;
    int inNum;
    Numero primoActual(0,true);
    
    cout << "Ingrese un Numero: " << endl;
    cin >> inNum;

    if (inNum < 2)
    {
        cout << "Ingrese un numero mayor a 2." << endl;
        return 0;
    }
    

    for (int i = 2; i <= inNum ; i++)
    {
        Criba.push_back(Numero(i,true));
        cout << Criba[i-2].getNumero() << endl;
    }

    vector<Numero>::iterator it = Criba.begin();
    primoActual = *it;

    do
    {
        vector<Numero>::iterator it2 = it + 1;

        for(; it2 <= Criba.end(); it2++)
        {
            Numero aux(0,true);
            aux = *it2;
            if(aux.getNumero() % primoActual.getNumero() == 0)
            {
                //cout << aux.getNumero() << endl;
                aux.setBooleano(false);
                *it2 = aux;
            }
        }
        it++;
        primoActual = *it;

    } while (pow(primoActual.getNumero(), 2) < inNum);
    
    vector<Numero>::iterator it3 = Criba.begin();

    for (; it3 != Criba.end(); it3++)
    {
        Numero aux(0,true);
        aux = *it3;
        if (!aux.getBooleano())
        {
            cout << aux.getNumero() <<"\t ";
        }
        
    }
    

}