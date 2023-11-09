
#include <algorithm>
#include <iostream>
using namespace std;

bool read_rational(int &num, int &den) {
  char c;
  if (cin >> num >> c >> den) {
    int x = __gcd(num, den);
    num = num / x;
    den = den / x;
    return true;
  }
  return false;
}

int main() {
  int numerador{0}, denominador{0};
  while (cin >> numerador >> denominador) {
    while (read_rational(numerador, denominador)) {
      cout << numerador <<" "<< denominador << endl;
    }
  }
}