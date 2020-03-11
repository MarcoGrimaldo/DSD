/*
all:
	gcc gfx.c -c
	g++ Marco_Antonio_Grimaldo_Peralta_DSD_4CM4_2.cpp -c
	g++ gfx.o Marco_Antonio_Grimaldo_Peralta_DSD_4CM4_2.o -o proyecto -lX11

*/


#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <stdlib.h>   
#include <iostream>
using namespace std;

#define PI 3.14159265

//####################################################

class Coordenada
{  
    private:
        double x;
        double y;
    public: 
        Coordenada(double = 0, double = 0);
        double obtenerX();
        double obtenerY(); 
};

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) 
{ }

double Coordenada::obtenerX()
{ 
    return x;
} 
double Coordenada::obtenerY()
{
     return y;
}

//####################################################

class Asteroide
{
    private:
        vector<Coordenada> vertices;
        Coordenada centro;
        double radio;
        double numVertices;
        int anguloDireccion;
        double alpha,beta,j;
    public:
        Asteroide(int x);
        void generaVertices();
        double getNumVertices();
        vector<Coordenada> getVertices();
        void inicializaAsteoriode();
        void setVertices(Coordenada newC,int at);
        Coordenada getCoordenadaVertice(int at);
        void mueveAsteroide();
        void giraAsteroide();
        Coordenada getCentro();
        void setAnguloDireccion(int nAngulo);
        int getAnguloDireccion();
        ~Asteroide();
};

Asteroide::Asteroide(int x) : numVertices(x)
{
    //  Generamos un centro y un radio al crear el objeto
    inicializaAsteoriode();
}

void Asteroide::inicializaAsteoriode()
{
    int x = rand() % 750 + 1;
    int y = rand() % 550 + 1;

    //Creamos el centro aleatorio
    centro = Coordenada(x,y);

    radio = rand() % 30 + 7;

    // Direccion aleatoria del asteroide
    anguloDireccion = rand() % 360;

    j = 0;
}

void Asteroide::generaVertices()
{
    double ranExt = 0;
    //  Angulo que cambiara para crear el asteoride
    alpha = 0;
    //  Angulo fijo 
    beta = 360.0 / numVertices;

    //  Obtenemos el centro aleatorio del asteroide
    double Xo = centro.obtenerX();
    double Yo = centro.obtenerY();

    //  Vamos a insertar una coordenada por cada n
    do {
        //  Vamos a sumar un numero aleatorio al radio
        ranExt = rand() % 20;

        //  Para radios pequenios se suma un numero pequenio
        if (radio < 50)
        {
            ranExt = rand() % 7;
            if(radio < 20)
            {
                ranExt = rand() % 3;
            }
        }        

        //   Convertimos Degrees a Rad
        alpha = (alpha * PI) / 180.0f; 

        //  Sumamos los sig. elementos para obtener coordenadas random (vertices)
        double Xi = Xo + (cos(alpha)*radio) + ranExt;
        double Yi = Yo + (sin(alpha)*radio) + ranExt;

        //  Regresamos Rad a Dregrees
        alpha = alpha / PI * 180.0;

        //  Se ingresan
        vertices.push_back(Coordenada(Xi,Yi));

        //  Sumamos el angulo
        alpha = alpha + beta;

    }while (alpha <= 361.0);
}

double Asteroide::getNumVertices()
{
    return numVertices;
}

Coordenada Asteroide::getCentro()
{
    return centro;
}

void Asteroide::setAnguloDireccion(int nAngulo)
{
    anguloDireccion = nAngulo; 
}

int Asteroide::getAnguloDireccion()
{
    return anguloDireccion;
}

vector<Coordenada> Asteroide::getVertices()
{
    return vertices;
}

void Asteroide::setVertices(Coordenada newC,int at)
{
    vertices.at(at) = newC;
}

Coordenada Asteroide::getCoordenadaVertice(int at)
{
    return vertices.at(at);
}

void Asteroide::mueveAsteroide()
{
    double Xo = centro.obtenerX();
    double Yo = centro.obtenerY();

    //cout << anguloDireccion << endl;


    for (int i = 0; i < vertices.size() ; i++)
    {
        double auxAng = (anguloDireccion * PI) / 180.0f;

        //  De acuerdo al angulo aleatorio se va a mover y a su ves la "velocidad" dependera del radio.
        Coordenada newCoordenada(vertices.at(i).obtenerX()+(cos(auxAng)*(20/radio)),vertices.at(i).obtenerY()+(sin(auxAng)*(20/radio)));
        setVertices(newCoordenada,i);

        //  Reseteamos el centro
        Coordenada newCentro(Xo+(cos(auxAng)*(20/radio)),Yo+(sin(auxAng)*(20/radio)));
        centro = newCentro;
    }
}

void Asteroide::giraAsteroide()
{
    alpha = 0;
    int i = 0;
    double velocidadGiro = PI / (radio*10);

    double Xo = centro.obtenerX();
    double Yo = centro.obtenerY();

    do {    
        //  alpha es en angulo de los vertices con respecto al centro
        alpha = (alpha * PI) / 180.0f; 

        //  Obtenemos la distancia del centro al vertice
        double distancia = sqrt( pow(vertices.at(i).obtenerX()-Xo,2) + pow(vertices.at(i).obtenerY()-Yo,2) );

        //  Guardamos el vertice pero agregamos "j" al angulo para que 
        //  en cada llamada a la funcion "giraAsteroide()" sume y gire
        double Xi = Xo + (cos(alpha + j)*distancia);
        double Yi = Yo + (sin(alpha + j)*distancia);

        alpha = alpha / PI * 180.0;

        setVertices(Coordenada(Xi,Yi),i);

        alpha = alpha + beta;
        i++;

    }while (alpha <= 361.0);

    j = j + velocidadGiro;
    
}

Asteroide::~Asteroide(){}

//####################################################

//  Verifica si el asteroide esta en pantalla
bool verificaAsteriodePantalla(Asteroide as)
{
    Coordenada centro = as.getCentro();
    double x = centro.obtenerX();
    double y = centro.obtenerY();

    if(x < 0.0)
        return false;
    if(y < 0.0)
        return false;
    if (x > 800.0)
        return false;
    if (y > 600.0)
        return false;
    
            
    return true;
}

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

int main(int argc, char *argv[])
{
    int t;
    int num;
    char c;

    if(argc != 2){
		cout << "Forma de uso: " << argv[0] <<" Numero-de-Asteroides\n";
		exit(0);
	}

    int numAsteroides = atoi(argv[1]);

    //int numAsteroides = 100;

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
            //  Si el centro del asteroide esta fuera de la pantalla
            if ( ! verificaAsteriodePantalla(Asteroides.at(i)) )
            {
                int ang = Asteroides.at(i).getAnguloDireccion();
                //  Suma 180 para que la direccion sea completamente la contraria
                //  y un numero random de 0 a 40 para que no tenga la misma trayectoria
                int nAng = ang + 180 + rand() % 40;
                
                //  El nuevo angulo de la suma anterior no debe pasar de 360
                nAng = nAng % 360;
                
                Asteroides.at(i).setAnguloDireccion(nAng);
            }
            
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
