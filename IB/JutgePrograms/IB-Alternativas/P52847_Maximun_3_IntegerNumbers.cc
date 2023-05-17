
#include <iostream>
using namespace std;
int main() {
  long long int Num1, Num2, Num3;
  // Pide números por teclado
  cin >> Num1 >> Num2 >> Num3;

  // Averigua el valor máximo de los valores pedidos
  if ((Num1 > Num2) and (Num1 > Num3)) {
    cout << Num1 << endl;
  } else if ((Num2 > Num1) and (Num2 > Num3)) {
    cout << Num2 << endl;
  } else if ((Num3 > Num1) and (Num3 > Num2)) {
    cout << Num3 << endl;
  } else if ((Num1 == Num2) or (Num1 == Num3) or (Num2 == Num3)) {
    if ((Num1 == Num3) or (Num1 == Num2)) {
      cout << Num1 << endl;
    } else if (Num2 == Num3) {
      cout << Num3 << endl;
    }
  }
  return 0;
}