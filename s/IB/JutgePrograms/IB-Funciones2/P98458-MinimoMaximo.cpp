
#include <algorithm>
#include <iostream>
using namespace std;

void min_max(int a, int b, int &mn, int &mx) {
  mn = min(a, b);
  mx = max(a, b);
}

int main() {
  int knumero_a{0}, knumero_b{0}, mn{0}, mx{0};
  while (cin >> knumero_a >> knumero_b) {
    min_max(knumero_a, knumero_b, mn, mx);
    cout << "min_max(" << 7 << ", " << -3 << ") → " << mn << ' ' << mx << endl;
  }
}