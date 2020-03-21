run: client.cpp server.cpp SocketDatagrama.o
	g++ server.cpp SocketDatagrama.o PaqueteDatagrama.o -o server
	g++ client.cpp SocketDatagrama.o PaqueteDatagrama.o -o client

SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c