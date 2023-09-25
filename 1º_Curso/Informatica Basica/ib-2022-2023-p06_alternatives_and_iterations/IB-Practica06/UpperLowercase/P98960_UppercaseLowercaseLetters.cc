/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file UppercaseLowercaseLetters.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 22 2022
 * @brief Write a program that reads a letter and prints it in lowercase if it
 * was uppercase, or prints it in uppercase if it was lowercase.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P31761
 */
#include <iostream>
using namespace std;
int main() {
  char letra;
  cin >> letra;
  if (letra == toupper(letra)) {
    letra = tolower(letra);
  } else
    letra = toupper(letra);
  cout << letra << endl;
  return 0;
}