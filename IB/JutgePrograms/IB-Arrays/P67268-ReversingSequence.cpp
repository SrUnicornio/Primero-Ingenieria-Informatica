
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int knumero{0};
  while (cin >> knumero) {
    vector<int> v(knumero);
    for (int i = 0; i < knumero; ++i) {
      cin >> v[i];
    }
    int aux;
    for (int j = 0; j < knumero / 2; ++j) {
      aux = v[j];
      v[j] = v[knumero - j - 1];
      v[knumero - j - 1] = aux;
    }
    for (int k = 0; k < knumero; ++k) {
      cout << v[k];
      if (k != knumero - 1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}