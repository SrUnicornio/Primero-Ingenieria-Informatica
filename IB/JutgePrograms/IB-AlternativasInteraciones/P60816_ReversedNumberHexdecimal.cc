
#include <iostream>
#include<string>
#include <algorithm>

using namespace std;

int main() {
  unsigned long long int NumDec{0};

  cin >> NumDec;
  char hex[100];
    
sprintf(hex, "%llX" , NumDec); /*uso de %llx permite combertir a hexadecimal sin tener que usar calculos complejos, y el ll sirve para que n existan errores con numeros execivamente grandes.*/
  
  string NumHexaDec(hex);
reverse(NumHexaDec.begin(),NumHexaDec.end());

  cout<< NumHexaDec<< endl;
  return 0;
}