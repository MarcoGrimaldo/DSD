#include "Coordenada.h"
#include "Asteroide.h"
#include <unistd.h>
#include <math.h>
#include <vector>
#include <stdlib.h>   
#include <iostream>
using namespace std;

#define PI 3.14159265

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