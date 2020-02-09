#include <iostream>
using namespace std;

int main(){

    double precio = 78.7;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << precio;
    cout << endl;

    return 0;
}