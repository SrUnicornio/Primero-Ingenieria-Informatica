#include <algorithm>
#include <string>
#include "Text-vowelmax.h"

void Usage(int argc, char *argv[]){
    if(argc != 2) {
        cout <<argv[0] <<": Falta el nombre del fichero" <<endl;
        cout <<"Pruebe" << argv[0] <<": --help para más información" <<endl;
        exit(EXIT_SUCCESS);
    }
    string parameter{argv[1]};
    if(parameter == "--help"){
        const string kHelperText = "Este programa averigua la palabra con mas vocales de un fichero de texto";
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}

void PalabraMasVocales(string kFichero) {
    string palabra;
    ifstream archivo;
    archivo.open(kFichero.c_str());
    string kVowel, aux;
    int kvocales{0};
    while (archivo >> palabra) {
        
        int vocales{0};
        for (int i = 0; i < palabra.length(); i++) {
            palabra[i] = tolower(palabra[i]);
            if (!isalpha(palabra[i])) {
                continue;
            }
            if (palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u') {
                vocales++;
            }
        }
        if (vocales > kvocales) {
            kvocales = vocales;
            kVowel = palabra;
        }
    }
    cout << "La palabra con mas vocales es: " << kVowel << endl;
}