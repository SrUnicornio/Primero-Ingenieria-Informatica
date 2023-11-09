
#include <iostream>
using namespace std;

void print(int s, char c, int n) {
  for (int i = 0; i < s; i++) {
    cout << " ";
  }
  for (int j = 0; j < n; j++) {
    cout << c;
  }
  cout << endl;
}

int main(){
int space, numero;
  char caracter;
  while (cin >>space >> caracter >> numero){
    print(space, caracter, numero);
  }
  
}