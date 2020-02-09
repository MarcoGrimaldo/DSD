main: main.cpp Rectangulo.o
	g++ main.cpp Rectangulo.o Coordenada.o -o p4
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
