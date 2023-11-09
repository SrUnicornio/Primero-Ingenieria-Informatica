#include <iostream>
#include <cstdlib>
#include "rotate_vowels.h"

void Usage(int argc, char *argv[]){
    if(argc != 2) {
        cout <<argv[0] <<": Falta el nombre del fichero" <<endl;
        cout <<"Pruebe" << argv[0] <<": --help para más información" <<endl;
        exit(EXIT_SUCCESS);
    }
    string parameter{argv[1]};
    if(parameter == "--help"){
        const string kHelperText = "Este programa rota las vocales en minúscula \ 
    que encuentre en el fichero que se le pase como parámetro por línea \
    de comandos, 'a' por 'e', 'e'por 'i','i' por 'o', 'o' por 'u', 'u' por 'a'";
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}

string rotate(string linea){
    for (int i = 0; i < linea.length(); ++i){
        switch (linea[i]){
        case 'a':
            linea[i] = 'e';
            break;
        case 'e':
            linea[i] = 'i';
            break;
        case 'i':
            linea[i] = 'o';
            break;
        case 'o':
            linea[i] = 'u';
            break;
        case 'u':
            linea[i] = 'a';
            break;
        }
    }
    return linea;
}