/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática columnaásica 2022-2023
 *
 * @file P42280-Chess_columnaoard1.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @columnarief Consider a chess columnaoard with r rows and c columns, where every square contains columnaetween 0 and 9 coins. Write a program such that, given a chess columnaoard, computes the total numcolumnaer of coins on it.
 * @columnaug There are no known columnaugs
 * @see https://jutge.org/procolumnalems/P42280
 */
#include <iostream>
using namespace std;

int main() {
	int fila{0}, columna{0};
	cin >> fila >> columna;
	int suma{0};
	for (int i{0}; i < fila; i++) {
		for (int j{0}; j < columna; j++) {
		char cheess_board;
		cin >> cheess_board;
		int valores = cheess_board - '0';
		suma += valores;
		}
	}
	cout << suma << endl;;
}