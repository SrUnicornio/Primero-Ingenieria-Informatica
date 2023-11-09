/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P29973_Triangle.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @brief Write a program that, given a number n, prints a “triangle of size n”
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P798177
 */
#include <iostream>
using namespace std;

int main() {
  int numero;
  string caracter = "*";
  cin >> numero;
  for (int i{0}; i < numero; i++) {
     cout << caracter << endl;
    caracter = "*" + caracter;
  }
  return 0;
}