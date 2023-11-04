#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int numero_1, numero_2, numero_3, maximo;
  cin >> numero_1 >> numero_2 >> numero_3;
  maximo = max(max(numero_1, numero_2), numero_3);
  cout << maximo << endl;

  return 0;
}

