
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string palabra;
  int knumero_palabras;
  cin >> knumero_palabras;
  vector<string> words(knumero_palabras);
  for (int i = knumero_palabras - 1; i >= 0; --i) {
    cin >> palabra;
    words[i] = palabra;
  }
  for (int j = 0; j < knumero_palabras; ++j) {
    palabra = words[j];
    reverse(palabra.begin(), palabra.end());
    cout << palabra << endl;
  }
}