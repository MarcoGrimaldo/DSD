#include "Fecha.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;


int masVieja1(Fecha fecha1, Fecha fecha2)
{
    if(fecha1.getAnio() > fecha2.getAnio())
		return 1;
	else if(fecha1.getAnio() == fecha2.getAnio()) 
    {
		if(fecha1.getMes() > fecha2.getMes())
			return 1;
		else if(fecha1.getMes() == fecha2.getMes()) 
        {
			if(fecha1.getDia() > fecha2.getDia())
				return 1;
			else if(fecha1.getDia() == fecha2.getDia())
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
}

int masVieja2(Fecha *fecha1, Fecha *fecha2)
{
    if(fecha1->getAnio() > fecha2->getAnio())
		return 1;
	else if(fecha1->getAnio() == fecha2->getAnio()) 
    {
		if(fecha1->getMes() > fecha2->getMes())
			return 1;
		else if(fecha1->getMes() == fecha2->getMes()) 
        {
			if(fecha1->getDia() > fecha2->getDia())
				return 1;
			else if(fecha1->getDia() == fecha2->getDia())
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
}

int main() {
    /*Fecha a, b, c(21, 9, 2030);
    int cont = 0;
    b.inicializaFecha(17, 6, 2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();*/
    srand (time(NULL));

    for (int i = 0; i < 80000000; i++)
    {

        int dd1 = rand() % 31 + 1;
        int mm1 = rand() % 12 + 1;
        int aaaa1 = rand() % 2020 + 1;

        Fecha f1(dd1,mm1,aaaa1);

        int dd2 = rand() % 31 + 1;
        int mm2 = rand() % 12 + 1;
        int aaaa2 = rand() % 2020 + 1;

        Fecha f2(dd2,mm2,aaaa2);

        /*f1.muestraFecha();
        f2.muestraFecha();
        cout << masVieja2(f1,f2) << endl;*/

        masVieja2(&f1,&f2);
    }
    
}
