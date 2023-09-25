// Path: Practica11-ejercisios\Complejo\Complejo_main.cpp

#include "Complejo.h"
using namespace std;

int main() {
  Complejo complejo1(1, 2);
  Complejo complejo2(3, 4);
  Complejo resultado;
  cout << "Complejo 1: " << complejo1 << endl;
  cout << "Complejo 2: " << complejo2 << endl;
  resultado = complejo1 + complejo2;
  cout << "Suma: " << resultado << endl;
  resultado = complejo1 - complejo2;
  cout << "Resta: " << resultado << endl;
  resultado = complejo1 * complejo2;
  cout << "Multiplicaion: " << resultado << endl;
  resultado = complejo1 / complejo2;
  cout << "Division: " << resultado << endl;
  return 0;
}