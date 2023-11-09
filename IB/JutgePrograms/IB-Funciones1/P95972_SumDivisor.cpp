
#include <iostream>
using namespace std;

int sum_divisors(int x) {
  int suma{0};
  int i;
  for (i = 1; (i * i) < x; ++i) {
    if (x % i == 0) {
      suma += i;
    }
  }
  for ( ; i >=1; --i){
    if ((x%i ==0) && (x/i != i-1)){
      suma += x/i;
    }
  }
  return suma;
}

int main() {
  unsigned int numero;
  while (cin >> numero) {
    cout << sum_divisors(numero) << endl;
  }
}