/* 
    Cada lado de un cuadrado es la raíz cuadrada del area 
     Xn = 1/2 *(Xv + a /Xv)

     Donde:
     Xn = Raíz aproximada
     Xv = Valo aproximado de la interacion anterior
     a = numero del cual se quiere saber la raiz

     - El ciclo finaliza cuando el valor absoluto de Xn - Xv es menor a 0.001
     - La ecuación se ejecuta la primera vez con Xn = Xo, donde Xo es conocido
*/

#include <iostream>
using namespace std;

int main()
{
    double n = 0;
    float xn = 0;
    int xv = 0;

    cout << "Ingrese el numero al que dessea calcular la raiz cuadrada: \n>";
    cin >> n;
    cout << "Ingrese un valor aproximado de la raiz cuadrada:\n>";
    cin >> xn;

    while( ( static_cast<int>(xn) - xv) > 0.001 )
    {
        xv = xn;
        xn = (1.0 / 2.0) * (xv + (n / xv) );
    }

    cout << "La raiz cuadrada de " << n << " es: ";
    std::cout.precision(5);
    std::cout << xn << endl;
}