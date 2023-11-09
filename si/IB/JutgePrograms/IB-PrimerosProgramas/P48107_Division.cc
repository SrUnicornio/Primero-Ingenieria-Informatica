
#include <iostream>
using namespace std;
int main() {

  long Num1, Num2;

  cin >> Num1 >> Num2;

  while (Num2 <= 0) {
    cin >> Num2;
  }

  cout << Num1 / Num2 << " " << Num1 % Num2 << endl;
  return 0;
}
