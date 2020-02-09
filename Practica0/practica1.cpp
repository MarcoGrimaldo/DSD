#include<stdio.h>

int main()
{
    char *pcaracter;   
    int *pentero; 
    float *pflotante; 
    long *plargo; 
    double *pdoble; 

    char caracter = 'x';   
    int entero = 12; 
    float flotante = 1.3; 
    long largo = 232; 
    double doble = 452; 

    char cadena[] = "ESCOM - IPN";

    printf("\n === Variables ===");

    printf("\nDireccion: %p | Longitud: %lu Contenido: %c",&caracter,sizeof(caracter),caracter);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %i",&entero,sizeof(entero),entero);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %f",&flotante,sizeof(flotante),flotante);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %ld",&largo,sizeof(largo),largo);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %f",&doble,sizeof(doble),doble);


    printf("\n === Apuntadores con basura ===");

    printf("\nDireccion: %p | Longitud: %lu Contenido: %c",&pcaracter,sizeof(pcaracter),pcaracter);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %i",&pentero,sizeof(pentero),pentero);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %f",&pflotante,sizeof(pflotante),pflotante);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %ld",&plargo,sizeof(plargo),plargo);
    printf("\nDireccion: %p | Longitud: %lu Contenido: %f",&pdoble,sizeof(pdoble),pdoble);

    //Asignamos el apuntador a la direccion
    pcaracter = &caracter;
    printf("\nContenido de pcaracter: %c",*pcaracter);

    for(int i = 0; i< 12 ; i++)
    {
        printf("\nDireccion: %p | Longitud: %lu Contenido: %x",&cadena[i],sizeof(cadena[i]),cadena[i]);
    }

    printf("\nCadena+4 : %c",cadena+4);

    printf("\n");
}