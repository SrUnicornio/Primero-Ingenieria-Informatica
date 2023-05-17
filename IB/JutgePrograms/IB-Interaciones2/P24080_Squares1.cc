/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file P24080_Squares1.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Nov 6 2022
 * @brief Write a program that prints squares with n2 n’s.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P24080
 */
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    int numero;
    int k{0};
    while (cin >> numero) {
        if (k == 0) k = 1;
        else cout << endl; 
        for (int i = 0; i < numero; i++) {
            for (int j = 0; j < numero; j++) {
                cout << numero;
            }
            cout << endl;
        }
    }
}