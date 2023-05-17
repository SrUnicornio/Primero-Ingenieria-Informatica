
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int numero_de_figuras{0};
    cin >> numero_de_figuras;
    if(numero_de_figuras == 0) {
        return 0;
    }
  
  const double pi = atan(1)*4;
    string figura;
    double altura{0}, base{0}, radio{0};
  
    for (int i = 0; i < numero_de_figuras; i++) {
        cin >> figura;
        if (figura == "rectangle") {
            cin >> altura >> base;
            cout << fixed << setprecision(6)<< altura*base << std::endl;
        }
        else if (figura == "circle") {
            cin >> radio;
            cout << fixed << setprecision(6)<< pi * pow(radio,2) << std::endl;
        }
    }
    return 0;
}