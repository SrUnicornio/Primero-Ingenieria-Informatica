#include <iostream>
using namespace std;

int main() {
  int numero{0}, resto{0}, suma{0};
  cout << "Public test case0 \n";
  cout << "Input \t Ouput\n";
  while (cin >> numero) {
    while (numero != 0) {
      resto = numero % 10;
      suma += resto;
      numero /= 10;
    }
    cout << suma << endl;
  }
  return 0;
}
