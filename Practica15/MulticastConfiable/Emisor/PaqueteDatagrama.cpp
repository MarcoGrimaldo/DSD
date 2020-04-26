#include <string.h>
#include <cstdlib>
#include "PaqueteDatagrama.h"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char* data, unsigned int datatam, char* dir, int port) {
    datos = new char[datatam];
    longitud = datatam;
    memcpy(datos, data, longitud);
    memcpy(ip, dir, sizeof(ip));
    puerto = port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam) {
    datos = new char[tam];
    longitud = tam;
}

PaqueteDatagrama::~PaqueteDatagrama() {
    delete[] datos;
    longitud = 0;
    puerto = 0;
}

char* PaqueteDatagrama::obtieneDireccion() {
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud() {
    return longitud;
}

int PaqueteDatagrama::obtienePuerto() {
    return puerto;
}

char* PaqueteDatagrama::obtieneDatos() {
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port) {
    puerto = port;
}

void PaqueteDatagrama::inicializaIp(char* dir) {
    memcpy(ip, dir, 16);
}

void PaqueteDatagrama::inicializaDatos(char* data) {
    memcpy(datos, data, longitud);
}