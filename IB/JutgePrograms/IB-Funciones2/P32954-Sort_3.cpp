
#include <iostream>
using namespace std;

void sort3(int &a, int &b, int &c) {
  if (a > b) {
    if (b > c) {
      swap(a, c);
    } else {
      if (c < a)
        swap(a, c);
      swap(a, b);
    }
  } else {
    if (b < c)
      ;
    else {
      if (c < a)
        swap(a, c);
      swap(c, b);
    }
  }
}
int main() {
  int x, y, z;
  while (cin >> x >> y >> z) {
    sort3(x, y, z);
    cout << x << ' ' << y << ' ' << z << endl;
  }
}
