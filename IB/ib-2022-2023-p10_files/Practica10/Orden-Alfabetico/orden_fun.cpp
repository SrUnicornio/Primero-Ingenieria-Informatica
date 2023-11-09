#include "orden_fun.h"

/**
 * @brief Esta función muestra el uso del programa.
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
        const string kHelperText = "Este programa separa las palabras \
        de un texto en ficheros que crea alfabéticamente";
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}

/** 
 *  @brief Esta función separa las palabras de un texto en ficheros que crea alfabéticamente.
 *  @param[in] texto: Texto del fichero del que extrae las palabras.
 */
void FicherosAlfabeticamente(const  string& texto) {
  string palabra{""};
  for (const auto &caracter_actual : texto) { 
    if (caracter_actual == ' ') {
      string primera_letra;
      primera_letra = toupper(palabra.at(0));
      ofstream fichero_salida{(primera_letra + ".txt"), ios::app}; 
      fichero_salida << palabra << endl;
      palabra = "";
    } else {
      palabra += caracter_actual;

    }
  }
}