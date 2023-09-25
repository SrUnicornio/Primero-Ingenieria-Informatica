/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básaica 2022-2023
 *
 * @file  Programa.cc
 * @author Alvaro Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 2 2022
 * @brief 
 */

#include <iostream>
using namespace std;

void inverpalabrao() {
  string palabra;  
  if (cin >> palabra) {
        inverpalabrao();
        cout << palabra << endl;
    }
}


int main() {
  inverpalabrao();

}
