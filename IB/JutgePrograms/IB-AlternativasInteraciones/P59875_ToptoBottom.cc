
#include <iostream>
using namespace std;
int main() {
  int Num1, Num2;

  cin >> Num1 >> Num2;

  if (Num1 == Num2) {
    cout << Num1 << endl;
    return 0;
  }

  if (Num2 > Num1) {
    do {
      cout << Num2 << endl;
      Num2 = Num2 - 1;
    } while (Num2 != Num1);
    cout << Num1 << endl;
  } else {
    do {
      cout << Num1 << endl;
      Num1 = Num1 - 1;
    } while (Num1 != Num2);
    cout << Num2 << endl;
  }

  return 0;
}
