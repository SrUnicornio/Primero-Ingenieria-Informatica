#include "ComputeInt.h"

int main() {
  int knumero;
  cout << "Introduce un numero: ";
  cin >> knumero;
  ComputeInt numero;
  numero.Perfecto(knumero);
  return 0;
}