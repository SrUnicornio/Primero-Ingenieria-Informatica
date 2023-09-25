/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Automata.cpp
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 27 2022
 * @brief Desarrollo de la clase Automata
 * @see https://github.com/IB-2022-2023/ib-2022-2023-p12_oop-AlvaroPerezRamos
 */
#include "Automata.h"

/**
 * @brief Esta función dice si el usuario ha introducido un parámetro o no.
 * @param[in] argc: Número de parámetros introducidos.
 * @param[in] argv: Parámetros introducidos.
 * @return No devuelve nada.
*/
void Usage(int argc, char *argv[]){
    if(argc != 2) {
        cout <<argv[0] <<": Falta el nombre del fichero" <<endl;
        cout <<"Pruebe" << argv[0] <<": --help para más información" <<endl;
        exit(EXIT_SUCCESS);
    }
    string parameter{argv[1]};
    if(parameter == "--help"){
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}

/**
 * @brief Esta función imprime el número de estados, el estado de arranque y los estados de aceptación.
 * @param[in] fichero: Fichero desde el que leen los valores.
 * @return No devuelve nada.
*/
void Automata::Cardinal(const string fichero) {
  ifstream archivo{fichero, ios::in};
  int numero_estados; int estado_arranque; string alfabeto;
  archivo >> numero_estados >> estado_arranque; // Extraemos los dos primeros números
  cout << "Numero de Estados: " << numero_estados << endl;
  cout << "Estado de arraque" << estado_arranque << endl;
  string Alfabeto{"Alfabeto: {"};
  while (archivo >> alfabeto) {
    Alfabeto += alfabeto;
    Alfabeto += ", ";
  }
  for (int i = 0; i < static_cast<int>(Alfabeto.length()) - 2; ++i) { // El -2 es para no añadir un ", " que sobra al final
    cout << "}";
  }
  string estados_aceptados{"Estados de acceptacion: {"};
  string linea{""};
  while (getline(archivo, linea)) {
    if (linea.length() > 0) {
      if (linea.at(2) == '1') { // Si el segundo caracter es 1, lo guardamos
        estados_aceptados += linea.at(0);
        estados_aceptados += ", ";
      }
    }
  }
  for (int i = 0; i < static_cast<int>(estados_aceptados.length()) - 2; ++i) { // El -2 es para no añadir un ", " que sobra al final
    cout << estados_aceptados[i];
  }
  cout << "}" << endl;
}

/**
 * @brief Esta función imprime la función de transición.
 * @param[in] fichero: Fichero desde el que leen los valores.
 * @return No devuelve nada.
*/

void Automata::FuncionTransicion(const string fichero) {
  ifstream archivo{fichero, ios::in};
  string estado;
  cout << "Funcion de transicion:" << endl;
  while (getline(archivo, estado)) {
    if (estado.length() > 0) {
      cout << estado << endl;
    }
  }
}