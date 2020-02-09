/*Ejercicio 2*/
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main( ) {
    //int numeroDeLenguajes;
    cout << "!!!Hola!!!.\n" << "Bienvenido a C++.\n";
   /* cout << "Cuantos lenguajes de programación dominas? ";
    cin >> numeroDeLenguajes;
    if (numeroDeLenguajes < 1){
        cout << "Sería recomendable aprender antes un lenguaje más sencillo...\n" << "por ejemplo C, aunque nada es imposible.\n";
    }
    else{
        cout << "Este curso será sencillo para ti.\n";  
    }*/

    cout << "Ejercicio 1 Calculo del area del circulo" << endl;
    const double PI = 3.1415926;
    int radio;
    //cout << "Ingrese el valor de PI: "; cin >> PI; MArca error al momento de compilar
    cout << "Ingrese el radio del Circulo: "; cin >> radio; 
    cout << "\nEl area del circulo es: " << PI*(pow(radio,2)) << endl;

    cout << "\nDivision de numeros EJERCICIO 2" << endl; 
    int num1=11,num2=5;
    float num3=22.5,num4=30.4;
    cout << "Division de enteros es: "  << num1/num2 << endl;
    cout << "Division de entero y flotante: " << num1/num3 << endl;

    cout << "\nEjercicio 3 y 4 Casteo" << endl;
    double c = 20;
    float f;
    //float a=9, b=5;
    f = static_cast<double>(9)/5 * c + 32.0;    
    cout << "Grados F: " << f << endl;

    cout << "\nEjercicio 5 Comparacion de Compiladores" << endl;
    int n=2;
    cout << "El valor de n + (++n) es: " << n + (++n) << endl;

    cout << "\nEjercicio 6 Variable precio(Punto decimal) " << endl;
    double precio = 78.7;
    /*Que imprima ciertos numeros del punto decimal*/
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);// cantidad de numeros despues del punto decimal
    cout << "El precio es: " << precio << endl;

    cout << "\nEjercicio extra " << endl;
    string nombre;
    cout << "Cual es tu nombre? " << endl; cin >> nombre; 
    cout << "Hola " << nombre <<endl; 


    return 0;
 } 