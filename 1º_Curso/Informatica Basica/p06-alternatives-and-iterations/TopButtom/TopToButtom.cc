/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file TomtoButtom.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 22 2022
 * @brief Write a program that reads two numbers x and y, and prints all numbers
 *between x and y (or between y and x), in decreasing order. Print all integer
 *numbers between x and y (or between y and x), in decreasing order.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P59875
 */
#include <iostream>

int main() {
  int knumero1, knumero2;

  std::cin >> knumero1 >> knumero2;

  if (knumero1 == knumero2) {
	  std::cout << knumero1 << std::endl;
    return 0;
  }

  if (knumero2 > knumero1) {
    do {
	    std::cout << knumero2 << std::endl;
      knumero2 -= 1;
    } while (knumero2 != knumero1);
    std::cout << knumero1 << std::endl;
  } else {
    do {
	std::cout << knumero1 << std::endl;
	knumero1 -= 1;
    } while (knumero1 != knumero2);
    std::cout << knumero2 << std::endl;
  }

  return 0;
}

