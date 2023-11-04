
#include <iostream>
using namespace std;

bool is_balanced(int n) {
  int sum, sumOdd, digit;
  sum = sumOdd = 0;  
  for (int i = 0; n != 0; ++i) {
    digit = n%10;
    if (i%2 == 0){
      sum += digit;
    }else {
      sumOdd += digit;
    }
    n /= 10;
  }
  return (sum == sumOdd);
}

int main(){
  int numero;
  cin >> numero;
  cout << is_balanced(numero) << endl;
return 0;
}
