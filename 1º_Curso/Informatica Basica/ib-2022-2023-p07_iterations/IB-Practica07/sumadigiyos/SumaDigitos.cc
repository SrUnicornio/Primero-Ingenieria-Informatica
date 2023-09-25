/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file SumaDigitos.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 9 2022
 * @brief Write a function that tells if a natural n is perfect.
 * @bug There are no known bugs
 * @see https://github.com/IB-2022-2023/P07-iterations/blob/main/iterations.md
 */
#include <iostream>
using namespace std;

int main() {
  int numero{0}, resto{0}, suma{0};
  cout << "Public test case0 \n";
  cout << "Input \t Ouput\n";
  while (cin >> numero) {
    while (numero != 0) {
      resto = numero % 10;
      suma += resto;
      numero /= 10;
    }
    cout << suma << endl;
  }
  return 0;
}