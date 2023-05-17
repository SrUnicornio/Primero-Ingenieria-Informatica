#include <iostream>
using namespace std;

void swap2(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

int main() {
  int knumero1{0}, knumero2{0};
  while(cin >> knumero1 >> knumero2){
  cout << swap2(knumero1, knumero2) << endl;
  }
}