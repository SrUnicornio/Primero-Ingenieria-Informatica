
#include <algorithm>
#include <iostream>
using namespace std;

void read_rational(int &num, int &den) {
  char c;
  cin >> num >> c >> den;
  int x = __gcd(num, den);
  num = num / x;
  den = den / x;
}

int main() {
  int numerador{0}, denominador{0};
  while (cin >> numerador >> denominador) {
    read_rational(numerador, denominador);
  }
}