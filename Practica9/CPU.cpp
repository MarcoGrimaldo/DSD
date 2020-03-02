#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath> 
using namespace std;

void calculosNumericos(double m) {
	double i = 0.0;
	double seno1 = 0.0;
	double cos1 = 0.0;
	double tan1 = 0.0;
	double log1 = 0.0;
	double raiz1 = 0.0;
	while(i < m) {
		seno1 += sin(i);
		cos1 += cos(i);
		tan1 += tan(i);
		log1 += log(i);
		raiz1 += sqrt(i);
		i += 1;
	}
}

int main() {
	double max = 121000000.0;
	calculosNumericos(max);
	return 0;
}