#include <iostream>
using namespace std;

class Fecha 
{
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int = 3, int = 4, int = 2014);
        void inicializaFecha(int, int, int);
        void muestraFecha();
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
};

Fecha::Fecha(int dd, int mm, int aaaa) 
{
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) 
{
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha() 
{
    cout << "La fecha es(dia-mes-anio): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAnio()
{
    return anio;
}

void Fecha::setDia(int d)
{
    dia = d;
}

void Fecha::setMes(int m)
{
    mes = m;
}

void Fecha::setAnio(int a)
{
    anio = a;
}

int main() 
{
    Fecha a, b, c(21, 9, 1973);

    b.inicializaFecha(17, 6, 2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();

    cout << "El dia es: " << c.getDia() << endl;
    cout << "El mes es: " << c.getMes() << endl;
    cout << "El anio es: " << c.getAnio() << endl;

    cout << "Modificando b" << endl;

    b.setDia(21); b.setMes(02); b.setAnio(1998);

    b.muestraFecha();

}