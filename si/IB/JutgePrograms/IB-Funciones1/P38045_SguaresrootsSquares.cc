
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  unsigned int numero{0};
  int cuadrado{0};
  int i{0};
  double raizcuadrada{0};
  while (cin >> numero) {
    cuadrado = pow(numero, 2);
    raizcuadrada = sqrt(numero);
      cout << cuadrado << " " << fixed << setprecision(6) << raizcuadrada
           << endl;
    }
  return 0;
}