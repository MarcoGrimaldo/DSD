#include <iostream>
using namespace std;

int main(){

    int n, sum;

    cin >> n;

    sum = n + (++n);

    cout << sum;
    cout << endl;



    return 0;
}