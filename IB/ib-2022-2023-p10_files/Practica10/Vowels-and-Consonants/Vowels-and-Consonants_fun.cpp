#include<iostream>
#include "Vowels-and-Consonants_fun.h"

/*Muestra el modo de uso*/
void Usage(int argc, char *argv[]){
    if(argc != 2) {
        cout <<argv[0] <<": Falta el nombre del fichero" <<endl;
        cout <<"Pruebe" << argv[0] <<": --help para más información" <<endl;
        exit(EXIT_SUCCESS);
    }
    string parameter{argv[1]};
    if(parameter == "--help"){
        const string kHelperText = "Este programa averigua la palabra más larga con vocales y otra con consonantes";
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}
//Busca la palbra mas larga con vocales y con consonantes y las imprime por pantalla
void PalabraLarga(string fichero){
    string palabras;
    ifstream archivo;
    archivo.open(fichero.c_str());
    string kVowel, kConsonat;
    int aux1{0}, aux2{0};
    if(archivo.fail()){
        cout << "No existe el archivo!" << endl;
    }
    while (archivo >> palabras) {
        int vowels{0}, consonant{0}, i;
        for (i = 0; i < palabras.length(); i++) {
            palabras[i] = tolower(palabras[i]);
            if (!isalpha(palabras[i])) {
                vowels = 0;
                consonant = 0;
            } else if (palabras[i] == 'a' || palabras[i] == 'e' || palabras[i] == 'i' || palabras[i] == 'o' || palabras[i] == 'u') {
                vowels++;
                if (aux1 < vowels) {
                    aux1 = vowels;
                    kVowel = palabras;
                }
            } else {
                consonant++;
                if (aux2 < consonant) {
                    aux2 = consonant;
                    kConsonat = palabras;
                }
            }
        }
    }
    cout << kVowel << " " << kConsonat << endl;
}
