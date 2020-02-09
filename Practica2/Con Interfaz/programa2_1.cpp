#include "Fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha a, b, c(21, 9, 2030);
    int cont = 0;
    b.inicializaFecha(17, 6, 2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();

    cout << "==== Ejercicio 1 ====" << endl;
    cout << "El dia es: " << c.getDia() << endl;
    cout << "El mes es: " << c.getMes() << endl;
    cout << "El anio es: " << c.getAnio() << endl;

    cout << "Modificando b" << endl;

    b.setDia(21); b.setMes(02); b.setAnio(2020);

    b.muestraFecha();

    cout << "==== Ejercicio 3 ====" << endl;

    cout << "Convertida: " << b.convierte() << endl;

    cout << "==== Ejercicio 4 ====" << endl;

    if (a.leapyr())
    {
        cout << "El anio " << a.getAnio() << " Es bisiesto" << endl;
    }

    if (b.leapyr())
    {
        cout << "El anio " << b.getAnio() << " Es bisiesto" << endl;
    }
    
    if (c.leapyr())
    {
        cout << "El anio " << c.getAnio() << " Es bisiesto" << endl;
    }

    for(int i = 1 ; i <= 2020 ; i++)
    {
        Fecha x(1,1,i);
        if (x.leapyr())
        {
            cont++;
        }
        
    }

    cout << "Anios bisiestos hasta hoy: " << cont << endl;
}
