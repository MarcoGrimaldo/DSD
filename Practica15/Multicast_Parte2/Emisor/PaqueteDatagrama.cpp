#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char * datos, unsigned int longitud, char * ip, int puerto){

    this->longitud = longitud;
    this->puerto = puerto;
    this->datos = new char [this->longitud];
    memcpy(this->datos,datos,longitud);
    for(int i = 0; i < 16; i++)
        this->ip[i] = ip[i];
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud){

    this->longitud = longitud;
    this->datos = new char [this->longitud];
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete[] datos;
}

char* PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char* PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto){
    this->puerto = puerto;
}

void PaqueteDatagrama::inicializaIp(char* ip){
    for(int i = 0; i < 16; i++)
        this->ip[i] = ip[i];
}

void PaqueteDatagrama::inicializaDatos(char* datos){
    this->datos = new char [this->longitud];
    memcpy(this->datos,datos,longitud);
}
