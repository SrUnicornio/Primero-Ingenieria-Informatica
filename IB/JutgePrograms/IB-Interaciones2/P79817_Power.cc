/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P79817_Power.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
 * @brief Write a program to compute powers.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P798177
 */
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int exponente{0}, numero{0};
  while (cin >> numero >> exponente) {
    if (exponente < 0) {
      return 1;
    }
    cout <<fixed<<setprecision(0)<< pow(numero, exponente) << endl;
  }
}