#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void MaxMinPromed(int tamanio, vector<int> V) {
  double suma;
  for (int i = tamanio; i > 0; --i) {
    suma += V[i];
  }
  auto res = minmax_element(V.begin(), V.end());
  int min = *res.first;
  int max = *res.second;

  cout << "minimo: " << min << " maximmo:" << max
       << " promedio: " << suma / tamanio << endl;
}

int main() {
  int tamanio;
  double suma;

  cin >> tamanio;
  vector<int> V(tamanio);
  for (int i = 0; i < tamanio; ++i) {
    cin >> V[i];
  }
  MaxMinPromed(tamanio, V);
}
