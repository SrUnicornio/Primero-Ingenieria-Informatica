
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long int Num1;
  string binario = "";
  cin >> Num1;
//comprobamso que sea superior a cero, en caso de ser 0 el resultado es 0
  while (Num1 < 0) {
    cin >> Num1;
  }
  if (Num1 == 0) {
    binario = "0";
  }
//calculamos cómo es en sistema binario
  while (Num1 > 0) {
    if (Num1 % 2 == 0) {
      binario = "0" + binario;
    } else {
      binario = "1" + binario;
    }
    Num1 = Num1 / 2;
  }

  reverse(binario.begin(), binario.end());
  cout <<binario<<endl;
}
