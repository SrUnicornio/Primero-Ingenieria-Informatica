/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P80660_CollanzSequence.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
 * @brief Let n be any strictly positive natural number. Consider the following process. If n is an even number, we divide it by two. Otherwise, we multiply it by 3 and add 1 to it. When we reach 1, we stop. For instance, starting with 3, we obtain the sequence
For every n, print how many steps are needed to reach 1. Suppose that this number is well defined, that is, that the conjecture of the statement is true.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P798177
 */
#include <iostream>
using namespace std;
int main() {
  unsigned int numero{0}, valor{0};
  while(cin >> numero){
    int i{0};
    if (numero==1) {cout<< i <<endl;continue;}
  do {
    if (numero % 2 == 0) {
      numero = (numero / 2);   
    } else {
      numero = (numero * 3) + 1;
    }
    i++;
  } while (numero > 1);
      cout << i <<endl;
    }
  return 0;
}