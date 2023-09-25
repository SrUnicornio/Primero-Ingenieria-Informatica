/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file  Concatenation.cc
 * @author Alvaro Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 25 2022
 * @brief Desarrolle un programa que incluya una función que tome como parámetros dos vectores y devuelva como resultado un tercer vector que sea la "concatenación" de los dos vectores pasados.
 * @see https://github.com/IB-2022-2023/P09-string-array-vector/blob/main/string-array-vector.md
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenation(const vector<int> &v1, const vector<int> &v2) {
  vector<int> V = v1;
  for (int i = 0; i < v2.size(); ++i) {
    V.push_back(v2[i]);
  }
  return V;
}

int main() {
  int vector1;
  while (cin >> vector1) {
    vector<int> V1(vector1);
    for (int i = 0; i < vector1; ++i) {
      cin >> V1[i];
    }
    int vector2;
    cin >> vector2;
    vector<int> V2(vector2);
    for (int i = 0; i < vector2; ++i) {
      cin >> V2[i];
    }
    vector<int> res = concatenation(V1, V2);
    cout << res.size() << endl;
    for (int i = 0; i < (int)res.size(); ++i) {
      cout << " " << res[i];
    }
    cout << endl;
  }
}
