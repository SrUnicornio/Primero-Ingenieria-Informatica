
#include <iostream>
#include <cmath>
using namespace std;

 int factorial(int n);
int main() {
short numero;
while (cin >>numero){
cout << "factorial("<<numero<<") → "<<factorial(numero)<<endl;
}
  return 0;
}
int factorial(int n){
  long kfactorial = 1.0;
  for(int i{1}; i<=n; i++){
    kfactorial *= i;
  } 
  return kfactorial;
}