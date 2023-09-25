/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Álvaro Pérez Ramos
 * @date Dic 3 2022
 * @brief Escriba un programa rotate.cc que rote las vocales en minúscula 
    que encuentre en el fichero que se le pase como parámetro por línea
    de comandos, entendiendo por rotar el cambio de 'a' por 'e', 'e'por 'i', 
    'i' por 'o', 'o' por 'u', 'u' por 'a'
 * @see https://github.com/IB-2022-2023/P10-files1/blob/main/files.md
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "rotate_vowels.h"

int main(int argc, char *argv[]) {
    Usage(argc, argv);
    string fichero = argv[1];
    string linea;
    ifstream archivo(fichero.c_str());
    if(archivo.fail()){
        cout << "No existe el archivo!" << endl;
        return 1;
    }
    while (getline(archivo, linea)) {
        cout << rotate(linea) ;
    } 
    archivo.close();
    system("pause");
}