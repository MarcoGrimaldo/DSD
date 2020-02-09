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

    int var = 1234567890;

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

    printf("\nVariable Decimal: %d | Hexadecimal: %x",var,var);

    var = - var;

    printf("\nVariable Decimal: %d | Hexadecimal: %x",var,var);

    int a = 0;
    int b = 1;
    int c = -1;
    int d = 2;
    int e = -2;
    int f = 3;
    int g = -3;

    printf("\nDireccion: %p |Contenido: %d",&a,a);
    printf("\nDireccion: %p |Contenido: %d",&b,b);
    printf("\nDireccion: %p |Contenido: %d",&c,c);
    printf("\nDireccion: %p |Contenido: %d",&d,d);
    printf("\nDireccion: %p |Contenido: %d",&e,e);
    printf("\nDireccion: %p |Contenido: %d",&f,f);
    printf("\nDireccion: %p |Contenido: %d",&g,g);

    printf("\n");
}