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
 * @see https://jutge.org/problems/P58153 */

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	double  numero1, numero2;
	while (cin >> numero1 >> numero2) {
	double H{0.0};
    for (int i = numero2 + 1; i <= numero1; i++) {
      H += 1.0 / i;
    }
    cout << fixed << setprecision(10) << H << endl;
	}
} 
