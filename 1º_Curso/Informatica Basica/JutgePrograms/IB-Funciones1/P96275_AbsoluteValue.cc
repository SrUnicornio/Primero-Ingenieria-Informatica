
#include <iostream>
#include <cmath>
using namespace std;

int absolute(int n);

int main() {
    int numero;
    cin >> numero;
    cout << "absolute("<<numero<<") → "<<absolute(numero) << endl;
}

int absolute(int n){
    return fabs(n);
}