
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double angulo;
  double seno;
  double coseno;
  const double pi=atan(1)*4;
  while (cin >> angulo) {
    seno = sin(angulo/180*pi);
    coseno = cos(angulo/180*pi);
    cout << fixed << setprecision(6) << seno << " " << coseno << endl;
  }
  return 0;
}