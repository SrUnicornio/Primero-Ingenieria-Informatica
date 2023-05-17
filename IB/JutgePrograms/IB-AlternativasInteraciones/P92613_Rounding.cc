
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double numero;
  int redondeobajo, redondeoalto, redondeo;
  cin >> numero;
  redondeoalto = ceil(numero);
  redondeobajo = floor(numero);
  redondeo = round(numero);

  cout << redondeobajo << " " << redondeoalto << " " << redondeo << endl;
}