
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  unsigned int numero;
  while (cin >> numero) {
    cout << "Public test case \nInput \t\t Ouput \n"<< numero << " \t\t\t";
    int fibo1{0}, fibo2{1};
    cout << fibo1 << " ";
    for (int i = 2; i <= numero; i++) {
      cout << fibo2 << " ";
      fibo2 = fibo1 + fibo2;
      fibo1 = fibo2 - fibo1;
    }
  }
  return 0;
}