#include <iostream>
using namespace std;
int main() {
  long int numero, cociente = 0, divisor = 1, numero_digitos = 0;
  cin >> numero;

  while (numero < 0) {
    cin >> numero;
  }

  while (cociente != 1) {
    numero_digitos++;
    divisor *= 10;
    cociente = numero / divisor;
    if (cociente == 1) {
      cout << "The number of digits of " << numero << " is " << numero_digitos + 1<<"."
           << endl;
    }

    if (cociente < 1) {
      cout << "The number of digits of " << numero << " is " << numero_digitos<<"."
           << endl;
      cociente = 1;
    } 
  }
  return 0;
}



