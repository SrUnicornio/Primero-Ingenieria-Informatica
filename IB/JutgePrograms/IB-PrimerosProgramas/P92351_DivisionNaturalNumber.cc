
#include <iostream>
using namespace std;
int main() {

  long long Num1, Num2, cociente, resto;
  cin >> Num1 >> Num2;
  if (Num2 == 0) {
    cin >> Num2;
  }

  cociente = Num1 / Num2;
  resto = Num1 % Num2;
  
  int i = 0;
  if (cociente < 0) {
    do {
      cociente = cociente + i;
      i--;
    } while ((cociente * Num2) > Num1);
    resto = Num1 - (Num2*cociente);
  }
  cout << cociente << " " << resto << endl;
  return 0;
}
