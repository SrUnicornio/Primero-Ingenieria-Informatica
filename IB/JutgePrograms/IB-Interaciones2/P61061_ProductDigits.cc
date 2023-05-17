/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P61061_ProductDigits.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
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
      n= numero;
      int product{1};
      while (numero != 0) {
        product *=  (numero % 10);
        numero = numero / 10;
      }
cout << "The product of the digits of " << n << " is " << product << "."
           << endl;
      numero = product;
    }
    cout << "----------"<<endl;
    }
  return 0;
}