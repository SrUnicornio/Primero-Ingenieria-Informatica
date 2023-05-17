/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P58153_HarmoicalNumbers_2.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
 * @brief Write a program that reads pairs of numbers n and m with n ≥ m, and
 * for each pair prints Hn − Hm.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P58153
 */
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double numero1, numero2;
  while (cin >> numero1 >> numero2) {
    double H{0.0};
    for (int i = numero2 + 1; i <= numero1; i++) {
      H += 1.0 / i;
    }
    cout << fixed << setprecision(10) << H << endl;
  }
}