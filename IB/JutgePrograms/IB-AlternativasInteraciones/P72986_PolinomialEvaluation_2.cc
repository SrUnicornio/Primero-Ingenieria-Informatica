
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    double numero{0}, base{0}, total{0.0};
    int coeficiente{0};
    cin >> base;
    vector<double> numeros;
    while (cin >> numero) {
        numeros.push_back(numero);
        coeficiente++;
    }
    for (int i = 0; i < coeficiente; i++) {
        total += numeros[i] * pow(base, coeficiente - i - 1);
    }
    cout << fixed << setprecision(4) << total << endl;

    return 0;
}