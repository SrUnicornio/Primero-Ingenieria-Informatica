/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P39359_Squares3.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @brief Write a program that prints squares n × n. To fill all the squares, start using 0, 1, …, 9, 0, etc
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P39359
 */
#include <iostream>
using namespace std;

int main() {
  int numero{0}, cuadrado{0}, espacio{0};
  while (cin >> numero) {
    if (espacio == 0) {
      espacio = 1;
    } else {
      cout << endl;
    }
    for (int i{0}; i < numero; i++) {
      for (int j{0}; j < numero; j++) {
        cout << cuadrado;
        cuadrado += 1;
        if (cuadrado > 9)
          cuadrado = 0;
      }
      cout << endl;
    }
  }
}