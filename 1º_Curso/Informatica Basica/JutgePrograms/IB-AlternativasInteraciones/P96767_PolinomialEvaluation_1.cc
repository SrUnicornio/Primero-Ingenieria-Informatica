
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
 double numero{0}, base{0}, total{0.0};
    int coeficiente{0};
    cin >> base;
    while (cin >> numero) {
        total = (numero * pow(base,coeficiente)) + total;
        coeficiente++;
    }
    cout << fixed << setprecision(4) << total << endl;

    return 0;
}