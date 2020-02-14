#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string line;
    cin >> n;
    cin.ignore();
    getline(cin, line);

    cout << line << endl;

    string cadena("ESCOM");
    cout << cadena.at(4) << endl;
}