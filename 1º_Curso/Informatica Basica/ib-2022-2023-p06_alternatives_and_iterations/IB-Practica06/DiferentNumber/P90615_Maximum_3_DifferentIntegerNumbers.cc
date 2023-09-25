/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Maximo of three integer numbers.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 22 2022
 * @brief Write a program that reads three numbers, all different, and prints
 * their maximum. Write a program that reads three numbers, all different, and
 * prints their maximum.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P90615
 */
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int numero_1, numero_2, numero_3, maximo;
  cin >> numero_1 >> numero_2 >> numero_3;
  maximo = max(max(numero_1, numero_2), numero_3);
  cout << maximo << endl;

  return 0;
}

