
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int contador(string frase, char letra) {
  return count(frase.begin(), frase.end(), letra);
}
int main(void) {
  string input;

  int n, s, w, e; //‘n’ for north, ‘s’ for south, ‘e’ for east, and ‘w’ for west
  getline(cin, input);

  n = contador(input, 'n');
  s = contador(input, 's');
  w = contador(input, 'w');
  e = contador(input, 'e');

  cout << "(" << e - w << ", " << s - n << ")" << endl;
  return 0;
}