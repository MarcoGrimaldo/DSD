#include "gfx.h"
#include "Coordenada.h"
#include "Asteroide.h"
#include <unistd.h>
#include <time.h>  
#include <stdlib.h>  
#include <iostream> 

using namespace std;

void dibujaAsteroides(Asteroide as)
{
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

    int numAsteroides = 100;

    vector<Asteroide> Asteroides;

    srand (time(NULL));
    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0,255,255);
    
    gfx_clear();

    //  Generamos los asteroides
    for (int i = 0; i < numAsteroides; i++)
    {
        //  Numero random de lados
        num = rand() % 15 + 10;
        Asteroides.push_back(Asteroide(num));
        Asteroides.at(i).generaVertices();
    }

    //  Mover y rotar
    for (int i = 0; i < 1000; i++)
    {
        gfx_clear();
        //  Cada Asteroide se modifica en este ciclo
        for (int i = 0; i < numAsteroides; i++)
        {
            Asteroides.at(i).giraAsteroide();
            Asteroides.at(i).mueveAsteroide();
            dibujaAsteroides(Asteroides.at(i));
        }
        gfx_flush();
        usleep(41666);
    }
    
    
    while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}
    return 0;
}
