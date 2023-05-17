
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  long long int Num1, NumDigitosinicial, invertido = 0, resto, NumDigitosfinal;
  cin >> Num1;

  while (Num1 < 0) {
    cin >> Num1;
  }

  while (Num1 != 0) {
    resto = Num1 % 2;
    Num1 = Num1 / 2;
    invertido = invertido * 10 + resto;
  }
cout <<invertido<<endl;
  return 0;
  }