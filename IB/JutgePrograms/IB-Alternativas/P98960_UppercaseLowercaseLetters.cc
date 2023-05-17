
#include <iostream>
using namespace std;
int main() {
  char letra;
  cin >> letra;
  if (letra == toupper(letra)) {
    letra = tolower(letra);
  } else
    letra = toupper(letra);
  cout << letra << endl;
  return 0;
}