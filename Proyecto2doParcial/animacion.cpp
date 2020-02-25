#include "gfx.h"
#include "Coordenada.h"
#include "Asteroide.h"
#include <unistd.h>
#include <time.h>  
#include <stdlib.h>  
#include <iostream> 
using namespace std;
int main()
{
    int t;
    int num;
    char c;

    srand (time(NULL));
    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0,0,255);

    num = 20;

    Asteroide as(num);

    as.generaVertices(num); // ########### OJO

    vector<Coordenada> ver = as.getVertices();

    gfx_clear();

    //  Dibujemos los vertices
    for (int i = 0; i <= num; i++)
    {
        //  Si es el final del recorrido se toma el ultimo vertice y se une con el primero
        if (i == num)
        {
            gfx_line(ver.at(i).obtenerX()*10,ver.at(i).obtenerY()*10,ver.at(0).obtenerX()*10,ver.at(0).obtenerY()*10);    
            break;
        }
        //  Se toma el primer vertice y se une con el siguiente
        gfx_line(ver.at(i).obtenerX()*10,ver.at(i).obtenerY()*10,ver.at(i+1).obtenerX()*10,ver.at(i+1).obtenerY()*10);
    }
    
    while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

    /*for(t = 0; t < 1000; t++)
    {
        gfx_clear();
        gfx_line( t*1+80, t*2+40, t*2+40, t*3+80 );
        gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
        gfx_flush();usleep(41666);  //24 por segundo
    }*/
    return 0;
}
