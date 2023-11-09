#include <iostream>
#include "cripto_fun.h"

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
      cout << argv[0] << "-- Cifrado de ficheros." << endl;
      cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << endl;
      cout << "fichero_entrada:  Fichero a codificar \n \
              fichero_salida:   Fichero codificado \n \
              método:           Indica el método de encriptado \n \
                                  1: Cifrado XOR \n \
                                  2: Cifrado de César \n \
              password:         Palabra secreta en el caso del método 1, valor de k en el método 2 \n \
              operación:        Operación a realizar en el fichero \n \
                                  +: encriptar el fichero \n \
                                  -: desencriptar el fichero \n";
    exit(EXIT_SUCCESS);
    }
}

/**
 * @brief Esta función crea un archivo encriptado
 * @param[in] cadena: Cadena a encriptar.
 * @return No devuelve nada.
 */

void Encoding(string cadena){
  ofstream encrypt;
  encrypt.open("encrypt.txt", ios::app);
      if(encrypt.fail()){
      cout << "Error! \n";
  } else {
      encrypt << cadena << endl;
      encrypt.close();
  }
}

/**
 * @brief Esta función crea un archivo desencriptado
 * @param[in] cadena: Cadena a desencriptar.
 * @return No devuelve nada.
 */

void Decoding(string cadena){
    ofstream decrypt;
    decrypt.open("decrypt.txt", ios::app);
        if(decrypt.fail()){
        cout << "Error! \n";
    } else {
        decrypt << cadena << endl;
        decrypt.close();
    }
}

/**
 * @brief Esta función encripta o desencripta según el operador elegido
 * @param[in] kOperador: Operador elegido.
 * @param[in] line: Cadena a encriptar o desencriptar.
 * @param[in] code: Valor de k.
 * @return No devuelve nada.
 */

void Cesar_Metod(char kOperador, string line, int code){
  string kCodificado = "";
  string kDecodificado = "";
  switch (kOperador){
  case '+':
    for (int i = 0; i < line.length(); ++i){
      if(!isalpha(line[i])){
        kCodificado += (int(line[i]));
      } else if (isupper(line[i])){
        kCodificado += (int(line[i] + code - 65) % 26 + 65);
      } else{
        kCodificado += (int(line[i] + code - 97) % 26 + 97);
      }
    }
    Encoding(kCodificado);
    break;
  case '-':
    code = 26 - code;
    for (int i = 0; i < line.length(); ++i){
      if(!isalpha(line[i])){
          kDecodificado += (int(line[i]));
      } else if (isupper(line[i])){
        kDecodificado += (int(line[i] + code - 65) % 26 + 65);
      } else{
        kDecodificado += (int(line[i] + code - 97) % 26 + 97);
      }
    }
  Decoding(kDecodificado);
  break;
  }
}

/**
 * @brief Esta función encripta o desencripta según el operador elegido
 * @param[in] kOperator: Operador elegido.
 * @param[in] frase: Cadena a encriptar o desencriptar.
 * @param[in] pasword: Palabra secreta.
 * @return No devuelve nada.
 */

void Xor_Metod(char kOperator, string frase, string pasword) {
  string kXorMetod;
  int n = frase.length();
  int m = pasword.length();
  for (int i = 0; i < n; i++) {
    kXorMetod += frase[i] ^ pasword[i % m];
  }
  if (kOperator == '+') {
    Encoding(kXorMetod);
  } else {
    Decoding(kXorMetod);
  }
}

