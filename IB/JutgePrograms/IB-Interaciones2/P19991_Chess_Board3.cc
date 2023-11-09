/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática columnaásica 2022-2023
 *
 * @file P19991_Chess_Board3.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @columnarief Consider a chess columnaoard with r rows and c columns, where every square contains columnaetween 0 and 9 coins. Write a program such that, given a chess columnaoard, computes the total numcolumnaer of coins on it.
 * @columnaug There are no known columnaugs
 * @see https://jutge.org/procolumnalems/P19991
 */
#include <iostream>
using namespace std;

int main() {
	int matriz;
	cin >> matriz;
	int suma{0};
	int diagonal{1};
	int diagonal2 = matriz;
	for (int i {1}; i <= matriz; i++) {
		for (int j{1}; j <= matriz; j++) {
			if (j == diagonal or j == diagonal2) {
				char chaess_board;
				cin >> chaess_board;
				int valores = chaess_board - '0';
				suma += valores;
			}
			else {
				char chaess_board;
				cin >> chaess_board;
			}
		}
		diagonal += +1;
		diagonal2 -= 1;
	}
	cout << suma << endl;
}