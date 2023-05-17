
#include <iostream>
using namespace std;
int main() {
  int Num1, Num2=0;

  cin >> Num1;
  
if (Num1 ==0){cout << "0"<<endl; return 0;}
  if (Num1<0) {
    cin >> Num1;
  }
    cout << "0"<<endl;
    do {
     
      Num2 = Num2 + 1;
    
        cout << Num2 << endl;
    } while (Num2 != Num1);
    

  return 0;
}
