
#include <iostream>
#include <math.h>
using namespace std;
int main() {
  long long int Num1, cociente = 0, divisor = 1, NumDigitos = 0;
  cin >> Num1;

  while (Num1 < 0) {
    cin >> Num1;
  }
//Dividir n veces entre 10 = 10^n ó log10(Numero)=n
  NumDigitos = (log10(Num1) + 1);
  if (Num1==0){cout << "The number of digits of " << Num1 << " is 1."
       << endl;return 0;} 
  cout << "The number of digits of " << Num1 << " is " << NumDigitos<< "."
       << endl;
  return 0;
  }