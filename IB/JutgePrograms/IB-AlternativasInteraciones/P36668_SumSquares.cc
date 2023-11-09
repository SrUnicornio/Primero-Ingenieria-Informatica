
#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int Num1, j = 0, i = 0; // J rasultado, i variable que es potenciada
  cin >> Num1;

  while (Num1 < 0) {
    if (Num1 < 0) {
      cin >> Num1;
    }
  }
  //∑i=1^n i^2.

  do {

    j = pow(i, 2) + j;
    i++;
  } while (i <= Num1);

  cout << j << endl;
  return 0;
}