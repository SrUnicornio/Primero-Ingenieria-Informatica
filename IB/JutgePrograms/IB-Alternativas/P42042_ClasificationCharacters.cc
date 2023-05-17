
#include <iostream>
using namespace std;
int main() {
  int i = 0;
  char letra;

  cin >> letra;
  // comprobar que letra sea mayuscula o minuscual
  if (letra == toupper(letra)) {
    cout << "uppercase" << endl;
  } else {
    cout << "lowercase" << endl;
  }

  // Comprobar que letra es vocal mayuscula o minuscula

  if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' ||
      letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' ||
      letra == 'O' || letra == 'U') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }

  return 0;
}