/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Automata_main.cpp
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 27 2022
 * @brief Desarrollo de la clase Automata_main
 * @see https://github.com/IB-2022-2023/ib-2022-2023-p12_oop-AlvaroPerezRamos
 */
#include "Automata.h"

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  Automata automata;
  automata.Cardinal(argv[1]);
  automata.FuncionTransicion(argv[1]);
  return 0;
}