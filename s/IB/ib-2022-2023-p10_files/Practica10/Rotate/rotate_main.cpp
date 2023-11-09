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
