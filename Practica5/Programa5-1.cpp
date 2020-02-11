#include "Fecha.h"
#include <stdlib.h>
#include <iostream>  
using namespace std;

int main()
{
    Fecha a, b, c(21, 9, 2000);
    b.inicializaFecha(17, 6 , 2000);
    a.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha() " << a.getVecesMuestF() << " veces\n";
    b.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha() " << b.getVecesMuestF() << " veces\n";
    c.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha() " << c.getVecesMuestF() << " veces\n";
    return 0;
}