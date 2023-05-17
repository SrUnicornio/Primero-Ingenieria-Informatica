
#include <iostream>
using namespace std;

void factor(int n, int &f, int &q) {
  int i{2};
  q = 1;
  f = n;
  while (i * i <= n) {
    int j{0};
    while (n % i == 0 and n != 0) {
      ++j;
      n /= i;
    }
    if (j > q || (j == q && f > i)) {
      q = j;
      f = i;
    }
    ++i;
  }
}

int main() {
   int knumero{0};
  while (cin >> knumero) {
    int kfrecuence{0}, kquantity {0};
    factor(knumero, kfrecuence, kquantity);
  cout << kfrecuence << " " << kquantity << endl;}
  return 0;
}