#include "gfx.h"
#include "Coordenada.h"
#include "Asteroide.h"
#include <unistd.h>
#include <time.h>  
#include <stdlib.h>  
#include <iostream> 
#include <thread>
using namespace std;

void dibujaAsteroides(Asteroide as)
{
    as.generaVertices(); // ########### OJO

    vector<Coordenada> ver = as.getVertices();

    //  Unimos los vertices
    for (int i = 0; i <= as.getNumVertices(); i++)
    {
        //  Si es el final del recorrido se toma el ultimo vertice y se une con el primero
        if (i == as.getNumVertices()-1)
        {
            gfx_line(ver.at(i).obtenerX(),ver.at(i).obtenerY(),ver.at(0).obtenerX(),ver.at(0).obtenerY());    
            break;
        }
        //  Se toma el primer vertice y se une con el siguiente
        gfx_line(ver.at(i).obtenerX(),ver.at(i).obtenerY(),ver.at(i+1).obtenerX(),ver.at(i+1).obtenerY());
    }
}

int main()
{
    int t;
    int num;
    char c;

    vector<Asteroide> Asteroides;

    srand (time(NULL));
    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0,255,255);
    
    gfx_clear();

    for (int i = 0; i < 80; i++)
    {
        num = rand() % 15 + 10;
        Asteroides.push_back(Asteroide(num));
        dibujaAsteroides(Asteroides.at(i));
    }
    
    while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}
    return 0;
}
