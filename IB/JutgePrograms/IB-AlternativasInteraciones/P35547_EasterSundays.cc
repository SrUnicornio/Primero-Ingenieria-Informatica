
#include <iostream>
using namespace std;
int main() {
  int anio{0};
  while (cin >> anio) {
    if (anio < 1800 || anio > 9999) {
      cin >> anio;
    }
    int k{0}, x{0}, b{0}, c{0}, q{0}, p{0}, y{0}, z{0}, n{0}, e{0};
    int dia{0}, mes{0};
    k = anio / 100;
    x = anio % 19;
    b = anio % 4;
    c = anio % 7;
    q = k / 4;
    p = (13 + (8 * k)) / 25;
    y = (15 - p + k - q) % 30;
    z = ((19 * x) + y) % 30;
    n = (4 + k - q) % 7;
    e = ((2 * b) + (4 * c) + (6 * z) + n) % 7;
    if (z + e <= 9) {
      dia = 22 + z + e;
      mes = 3;
    } else if (z == 29 && e == 6) {
      dia = 19;
      mes = 4;
    } else if (z == 28 && e == 6 && x > 10) {
      dia = 18;
      mes = 4;
    } else {
      dia = z + e - 9;
      mes = 4;
    }
    cout << dia << "/" << mes << endl;
  }
  return 0;
}