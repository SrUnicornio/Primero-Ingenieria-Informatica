/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P79817_Power.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
 * @brief Write a program that reads several numbers and prints the sum of the digits of each one.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P33839
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int numero{0}, num1;
  
  while (cin >> numero) {
     num1=numero;
    int sumadigitos{0};
      do {sumadigitos += numero % 10;
      numero /= 10;}while (numero>0);
    cout << "The sum of the digits of " << num1 << " is " << sumadigitos<<"."
       << endl;
    
  }
return 0;
}