/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file LeapYears.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 25 2022
 * @brief
 * @bug There are no known bugs
 * @see Write a program that tells if a year is or is not a leap year.

A leap year has 366 days. After the Gregorian reform, the leap years are those
multiple of four that do not end with two zeros, and also the years ending with
two zeros such that, after removing these two zeros, are divisible by four.
Thus, 1800 and 1900, although being multiples of four, were not leap years; by
contrast, 2000 was a leap year.https://jutge.org/problems/61634
 */
#include <iostream>
using namespace std;
int main() {
  int anio;
   cout << "Public test case \nInput\t\tOuput\n";
  while (cin >> anio) {
    if (anio < 1800 || anio > 9999) {
      cin >> anio;
      continue;
    } else {
      if (anio % 4 == 0 and anio % 100 != 0 or anio % 400 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}