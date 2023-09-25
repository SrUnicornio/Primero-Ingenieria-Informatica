/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file HarmonicalNumber.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 22 2022
 * @brief Write a program that reads a number n and prints the n-th harmonic
 *number, defined as Hn = 1/1 + 1/2 + ⋯ + 1/n. Print Hn with 4 digits after the
 *decimal point
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P59539
 */
#include <iomanip> //al incluir iomanip podemos manipular diferntes parametros que requiera el porgrma
#include <iostream> 

using namespace std;
int main() {

  float Num1;
  double total = 0, i = 0;
  cin >> Num1;
  if (Num1 == 0) {
    cout << fixed << setprecision(4) << total << endl;
    return 0;
  }
  do {
    i++;
    total = total + (1 / i);

  } while (i < Num1);
  cout << fixed << setprecision(4) << total << endl;
  return 0;
}