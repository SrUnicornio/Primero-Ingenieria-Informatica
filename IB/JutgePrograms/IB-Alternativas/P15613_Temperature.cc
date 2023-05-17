
#include <iostream>
using namespace std;
int main() {
  int Num1;
  cin >> Num1;
  if ((Num1 <= 30) and (Num1 >= 10)) {
    cout << "it's ok" << endl;
  } 
  if ((Num1 > 30) and (Num1 < 100)) {
    cout << "it's hot" << endl;
  } 
if (Num1 >= 100) {
    cout << "it's hot"<<endl;
      cout   << "water would boil" << endl;
  } 
if ((Num1 < 10) and (Num1 > 0)) {
  cout << "it's cold" << endl;
  } 
if (Num1 <= 0) {
  cout << "it's cold"<<endl;
  cout   << "water would freeze" << endl;
  }
}