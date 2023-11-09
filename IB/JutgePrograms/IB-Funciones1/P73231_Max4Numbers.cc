
#include <algorithm>
#include <iostream>
using namespace std;

int max4(int a, int b, int c, int d);
int main() {
  int numero1{0}, numero2{0}, numero3{0}, numero4{0};
  while (cin >> numero1 >> numero2 >> numero3 >> numero4) {
    cout << "max4(" << numero1 << ", " << numero2 << ", " << numero3<< ", " << numero4<< ") → "
         << max4(numero1, numero2, numero3, numero4) << endl;
  }
  return 0;
}
int max4(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }