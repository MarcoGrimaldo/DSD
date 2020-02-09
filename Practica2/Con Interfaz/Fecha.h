#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
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
		int convierte();
		bool leapyr();
};
#endif
