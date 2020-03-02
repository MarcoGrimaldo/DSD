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
    generaCentroRadio();
}

void Asteroide::generaVertices()
{
    double ranExt = 0;
    //  Angulo que cambiara
    double alpha = 0;
    //  Angulo fijo
    double beta = 360.0 / numVertices;

    //  Obtenemos el centro del asteroide
    double Xo = centro.obtenerX();
    double Yo = centro.obtenerY();

    cout << "Origen: " << Xo << " , " << Yo << endl;
    cout << "Radio: " << radio << endl;

    //alpha = beta;

    //  Vamos a insertar una coordenada por cada n
    
    do {
        //  Vamos a sumar un numero aleatorio al radio
        ranExt = rand() % 20;
        if (radio < 50)
        {
            ranExt = rand() % 7;
            if(radio < 20)
            {
                ranExt = rand() % 3;
            }
        }        

        cout << "Random: " << ranExt << endl;

        //   Convertimos Degrees a Rad
        alpha = (alpha * PI) / 180.0f; 

        //  Sumamos los sig. elementos para obtener coordenadas random
        double Xi = Xo + (cos(alpha)*radio) + ranExt;
        double Yi = Yo + (sin(alpha)*radio) + ranExt;

        //  Regresamos Rad a Dregrees
        alpha = alpha / PI * 180.0;

        //  Se ingresan
        vertices.push_back(Coordenada(Xi,Yi));
        cout << "[ " << Xi << " , " << Yi << " ]\n";

        //  Sumamos el angulo
        alpha = alpha + beta;

    }while (alpha <= 361.0);
    
    cout << "Se generaron los vertices xd\n";
}

double Asteroide::getNumVertices()
{
    return numVertices;
}

void Asteroide::generaCentroRadio()
{
    int x = rand() % 800 + 1;
    int y = rand() % 700 + 1;

    //Creamos el centro aleatorio
    centro = Coordenada(x,y);

    radio = rand() % 30 + 7;
}

vector<Coordenada> Asteroide::getVertices()
{
    return vertices;
}

Asteroide::~Asteroide(){}