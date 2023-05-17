
#include <algorithm>
#include <iostream>
using namespace std;

bool is_palindromic(int n) {
  int numero{0}, girar{0};
  numero = n;
  while (numero != 0) {
    girar = girar * 10 + numero % 10;
    numero /= 10;
  }
  return n == girar;
}
int main() {
  int numero;
  while (cin >> numero) {
    cout << "is_palindromic(" << numero << ") → ";
    if (is_palindromic(numero) == 1) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
}