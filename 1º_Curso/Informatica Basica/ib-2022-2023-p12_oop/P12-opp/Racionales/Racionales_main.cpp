#include "Racionales.h"

int main() {
  int numerador, denominador;
  cout << "Introduce el numerador: ";
  cin >> numerador;
  cout << "Introduce el denominador: ";
  cin >> denominador;
  Racionales numero(numerador, denominador);
  numero.Inverso();
  return 0;
}