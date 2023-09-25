/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Program1.cc
 * @author Alvaro Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 17 2022
 * @brief Write a program that reads a number and prints its number of digits.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P55622
 */
#include <iostream>
using namespace std;
int main() {
  long int numero, cociente = 0, divisor = 1, numero_digitos = 0;
  cin >> numero;

  while (numero < 0) {
    cin >> numero;
  }

  while (cociente != 1) {
    numero_digitos++;
    divisor *= 10;
    cociente = numero / divisor;
    if (cociente == 1) {
      cout << "The number of digits of " << numero << " is " << numero_digitos + 1<<"."
           << endl;
    }

    if (cociente < 1) {
      cout << "The number of digits of " << numero << " is " << numero_digitos<<"."
           << endl;
      cociente = 1;
    } 
  }
  return 0;
}



