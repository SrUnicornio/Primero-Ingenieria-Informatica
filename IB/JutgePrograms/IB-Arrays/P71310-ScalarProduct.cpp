
#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double> &u, const vector<double> &v) {
  int knumero = v.size();
  double producto{0};
  for (int i = 0; i < knumero; i++) {
    producto += (v[i] * u[i]);
  }
  return producto;
}
int main() {
  int knumero_vectores;
  while (cin >> knumero_vectores) {
    vector<double> u(knumero_vectores);
    vector<double> v(knumero_vectores);
    for (int i = 0; i < knumero_vectores; ++i) {
      cin >> u[i];
    }
    for (int j = 0; j < knumero_vectores; ++j) {
      cin >> v[j];
    }
    cout << scalar_product(u, v) << endl;
  }
}