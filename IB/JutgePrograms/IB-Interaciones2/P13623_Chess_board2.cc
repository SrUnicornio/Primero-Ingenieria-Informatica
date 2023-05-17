/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 * @file P13623_Chess_board.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 4 2022
 * @brief Write a program such that, given a chess board, computes the total
 * number of coins on its white squares.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P13623
 */
#include <iostream>
using namespace std;


int main() {
	int fila{0}, columna{0}, total{0};
	cin >> fila >> columna;
	char chess_board;
	for (int i = 0; i < fila; ++i) {
		for (int j = 0; j < columna; ++j) {
			cin >> chess_board;
			if ((j + i) % 2 == 0) {
				total += chess_board - '0';
			}
		}
	}
	cout << total << endl;
}