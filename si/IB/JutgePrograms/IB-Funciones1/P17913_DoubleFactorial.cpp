
#include <iostream>
#include <cmath>
using namespace std;

 int double_factorial(int x);
int main() {
short numero;
while (cin >>numero){
cout << "factorial("<<numero<<") → "<<double_factorial(numero)<<endl;
}
  return 0;
}
int double_factorial(int x){
    int kfactorial{1};
    while (x > 0) {
        kfactorial = kfactorial*x;
        x -=2;
    }
    return kfactorial;
}
