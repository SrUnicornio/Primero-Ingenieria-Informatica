/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Logarithms.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 26 2022
 * @brief Write a program that computes logarithms in several bases.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P90133
 */
#include <cmath>
#include <iostream>
using namespace std;

int logbase(const int &numero, const int &base) {
  return (numero > (base - 1)) ? 1 + logbase(numero / base, base) : 0;
}

int main() {
  long int base, numero;
  int i{0};
  int result;
  while (cin >> base >> numero) {
    if (base < 2 || numero < 1) {
      return 1;
    }
    cout << logbase(numero, base) << endl;
  }
  return 0;
}