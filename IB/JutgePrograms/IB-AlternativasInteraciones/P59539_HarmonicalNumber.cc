
#include <iomanip> //al incluir iomanip podemos manipular diferntes parametros que requiera el porgrma
#include <iostream> 

using namespace std;
int main() {

  float Num1;
  double total = 0, i = 0;
  cin >> Num1;
  if (Num1 == 0) {
    cout << fixed << setprecision(4) << total << endl;
    return 0;
  }
  do {
    i++;
    total = total + (1 / i);

  } while (i < Num1);
  cout << fixed << setprecision(4) << total << endl;
  return 0;
}