
#include <iostream>
using namespace std;
int main() {
  int Num1, Num2, Num3;

  cin >> Num1 >> Num2;

  if (Num1 == Num2) {
    cout << Num1 << endl;
    return 0;
  }
  if (Num1 > Num2) {
    cout << endl;
    return 0;
  }

  do {
    printf("%d%s", Num1, ",");
    Num1 = Num1 + 1;

  } while (Num1 != Num2);
  printf("%d\n", Num1);
  return 0;
}