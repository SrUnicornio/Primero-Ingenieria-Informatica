
#include <algorithm>
#include <iostream>
using namespace std;

int max2(int a, int b);
int main() {
  int numero1, numero2;
  while (cin >> numero1 >> numero2) {
    cout << "max2(" << numero1 << ", " << numero2 << ") → "
         << max2(numero1, numero2) << endl;
    }
  return 0;
  }
    int max2(int a, int b) { return max(a, b); }