
#include <iostream>
using namespace std;

bool is_perfect(int n) {
  int divisor{1};
  for (int i{2}; i * i <= n; ++i) {
    if (n % i == 0)
      divisor += i + n / i;
  }
  if (divisor == n && n!=0 && n!=1) {
    return true;
  }
  return false;
}

int main() {
  int numero;
  while (cin >> numero) {
    cout << "is_perfect(" << numero << ") → ";
    if (is_perfect(numero) == 1) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
}