/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito-Izquierdo
 * @date Dec 17 2022
 * @brief Un programa cliente para la clase Automata
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>  // To use in srand()

#include "automaton.h"

/// Usage: the program requires 1 parameter: string
void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      const std::string kHelpText = "Este programa toma como parámetro un nombre de fichero con la definición de un DFA.";
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  else {
    std::cout << "El programa requiere un parámetro." << std::endl;
    std::cout << "Modo de uso:" << std::endl;
    std::cout << argv[0] << " <Nombre de fichero>" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/*
 * @brief main()
 * @param[in] arg: number of parameters in command line
 * @param[in] argv: array of (char*) parameters in command line
 * @return 0
 */
int main(int argc, char **argv) {
  Usage(argc, argv);
  std::string file_name{argv[1]};
  Automaton mi_dfa(file_name);
  mi_dfa.Print();
  return 0;
}
