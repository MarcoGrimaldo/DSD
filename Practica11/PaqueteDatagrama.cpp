#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char *cadena, unsigned int longitudDatagrama, char *direccionIP, int puertoPD){
     datos = new char[longitudDatagrama];
     longitud = longitudDatagrama;
     memcpy(datos, cadena, sizeof(char)*longitud);
     memcpy(ip, direccionIP, sizeof(char)*16);
     puerto = puertoPD;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitudDatagrama){
    datos = new char[longitudDatagrama];
    longitud = longitudDatagrama;
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete(datos);
}

char *PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char *PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puertoPD){
    puerto = puertoPD;
}

void PaqueteDatagrama::inicializaIp(char *direccionIP){
    memcpy(ip, direccionIP, sizeof(char)*16);
}

void PaqueteDatagrama::inicializaDatos(char *cadena){
    memcpy(datos, cadena, longitud);
}