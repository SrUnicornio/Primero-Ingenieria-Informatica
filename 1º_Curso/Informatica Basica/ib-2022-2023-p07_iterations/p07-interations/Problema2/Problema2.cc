/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Problema2.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 18 22
 * @brief Write a program that reads several numbers, and for each one prints the product of its digits, and the product of the digits of the latest product, etcetera, until the resulting product has just one digit.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P61061
 */
#include <iostream>
using namespace std;

int main() {
  unsigned int numero, n;
  
  while (cin >> numero) {
    if (numero<10){cout << "The product of the digits of " << numero << " is " << numero<< "."<<endl;}
    while (numero >= 10) {
		int producto{1};
		n = numero;
		while (numero != 0){
			producto *=(numero % 10);
			numero /= 10;
		}
		cout << "The product of the digits of " << n << " is " << producto << "."
           << endl;
      numero = producto;
    }
    cout << "----------"<<endl;
    }
  return 0;
}
