#include "DFA_fun.h"

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

void Cardinal(const string fichero) {
  ifstream archivo{fichero, ios::in};
  int numero_estados, estado_arranque; 
  archivo >> numero_estados >> estado_arranque; // Extraemos los dos primeros números
  cout << "|Q| = " << numero_estados << endl;
  cout << "q0 = " << estado_arranque << endl;
  string estados_aceptados{"F = {"};
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
  //return 0;
}

/** 
 *  @brief Esta función imprime los valores de la función de transición.
 *  @param[in] fichero: Fichero desde el que leen los valores.
 *  @return No devuelve nada.
 */
void FuncionTransicion(const string fichero) {
  ifstream archivo{fichero, ios::in};
  string estado{""};
  while (getline(archivo, estado)) {
    if (estado.length() > 1) { // Para ignorar los primeros números
      // cout << linea_estado << endl;
      cout << "delta(" << estado.at(0) << ", " << estado.at(6) << ") = " << estado.at(8) << endl;
      cout << "delta(" << estado.at(0) << ", " << estado.at(10) << ") = " << estado.at(12) << endl;
    }
  }
  //return 0;
}
