/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Problema3.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 18 2022
 * @brief Write a program to compute powers.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P798177
 */

#include <iostream>
using namespace std;

int main() {
	long int base{0}, exponente{0};
	while (cin >> base >> exponente){
	if (exponente == 1){
					cout << "1"<<endl;
				 	continue;}
		long int potenciado{1};
		for(int i = 0; i <= exponente; i++){
			potenciado *= base;
		}
	cout << potenciado << endl;
	}
	return 0;
}
