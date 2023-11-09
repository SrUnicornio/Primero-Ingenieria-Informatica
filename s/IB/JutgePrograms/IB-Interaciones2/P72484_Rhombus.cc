/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P72484_Rhombus.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @brief Write a program such that, given a number n, prints a “rhombus of size n”.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P72484
 */
#include <iostream>
using namespace std;

int main() {
  unsigned int numero{0};
  cin >> numero;
  if (numero<1){cin >> numero;}
  for (int i{1}; i<=numero; i++) {
    for (int j{i}; j <= numero-1; j++) {
      cout << " ";
    }
    for (int k{1}; k<= (2*i)-1; k++) {
      cout << "*";
    }cout<<endl;
  }
  for (int i{numero-1}; i>=1; i--) {
    for (int j{i}; j <= numero-1; j++) {
      cout << " ";
    }
    for (int k{1}; k<= (2*i)-1; k++) {
      cout << "*";
    }cout<<endl;
  }
  return 0;
}