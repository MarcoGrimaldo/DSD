#include "proyecto1_6.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
/**/

void Criba(int lim)
{
    int limite = lim, contPrimos = 0;
    vector<candidato> criba;
//------------------------------------------------------------------
//      INTRODUCIMOS EN EL VECTOR TODOS LOS NUMEROS DESDE 2 HASTA N
//------------------------------------------------------------------

    for (int i = 2; i <= limite; i++)
    {
        criba.push_back(candidato(i,true));
    }

//--------------------------------------------------------------------
//      DESCARTAMOS LOS VALORES QUE NO SON PRIMOS (SE CAMBIA A FALSE )
//--------------------------------------------------------------------
    for(int i = 2; i*i <= limite; ++i) {
        if(criba[i-2].primo) {
            for(int h = 2; i*h <= limite; ++h)
                criba[(i*h)-2].primo = false;
        }
    }
//-------------------------------------------------------------------------
//      IMPRIME LOS VALORES PRIMOS (TRUE)
//-------------------------------------------------------------------------
    for (int j =0 ; j <= limite-2; j++)
    {   
        if(criba[j].primo)
        {
            contPrimos++;
            cout<<criba[j].number << "   " ;
        }
    }
    cout <<"\n \tTotal de números primos encontrados desde 2 hasta " <<limite <<": " <<contPrimos <<endl;
}
