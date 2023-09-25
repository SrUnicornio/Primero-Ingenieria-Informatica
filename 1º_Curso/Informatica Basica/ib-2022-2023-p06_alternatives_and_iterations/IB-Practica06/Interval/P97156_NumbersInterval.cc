/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file  Numbers_inan_Interval.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 22 2022
 * @brief Write a program that reads two numbers a and b, and prints all numbers
 * between a and b.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P97156
 */
#include <iostream>
using namespace std;
int main() {
  int Num1, Num2, Num3;

  cin >> Num1 >> Num2;

  if (Num1 == Num2) {
    cout << Num1 << endl;
    return 0;
  }
  if (Num1 > Num2) {
    cout << endl;
    return 0;
  }

  do {
    printf("%d%s", Num1, ",");
    Num1 = Num1 + 1;

  } while (Num1 != Num2);
  printf("%d\n", Num1);
  return 0;
}