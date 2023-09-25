/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file  Programa.cc
 * @author Alvaro Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 2 2022
 * @brief 
 */

#include <iostream>
#include <vector>
using namespace std;

int position_maximum(const vector<double>& v, int m) {
  int max{0};
  double max_value = v[0];
  for (int i = 1; i <= m; ++i) {
    if (v[i] > max_value) {
      max = i;
      max_value = v[i];
    }
  }
  return max;
}

int main() {
  int tamanio;
  cin >> tamanio;
  vector<double> V(tamanio);
  for(int i = 0; i < tamanio; i++){
    cin >> V[i];
  }
  cout <<  position_maximum(V, tamanio) << endl;
  return 0;
}
