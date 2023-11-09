
#include <iostream>
#include "cripto_fun.h"

int main(int argc, char *argv[]) {
    Usage(argc, argv);
    string fichero = argv[1];
    fstream archivo(fichero.c_str());
    string linea;
    if(archivo.fail()){
        cout << "No existe el archivo!" << endl;
        return 1;
    }
    cout << "Indica el metodo de encriptado \n \
    1: Cifrado xor\n \
    2: Cifrado de Cesar \n";
    int kTipoCifrado;
    cin >> kTipoCifrado;
    while(kTipoCifrado < 1 || kTipoCifrado > 2){
        cout << kTipoCifrado <<" Entrada erronea, use 1 o 2 para elegir metodo\n \
        1: Cifrado xor\n \
        2: Cifrado de Cesar \n";
        cin >> kTipoCifrado;
    }
    cout << "Operacion a realizar en el fichero \n\
    +: encriptar el fichero\n \
    -: desencriptar el fichero \n";
    char kOperacion;
    cin >> kOperacion;
    while (kOperacion != '+' && kOperacion != '-'){
        cout << kOperacion <<" Entrada erronea, use + o - para elegir la operaion\n\
        +: encriptar el fichero\n \
        -: desencriptar el fichero \n";
        cin >> kOperacion;
    }
    if(kOperacion == '+'){ofstream encrypt("encrypt.txt");
                    encrypt.clear();}
    if(kOperacion == '-'){ofstream decrypt("decrypt.txt");
                    decrypt.clear();} 
    if (kTipoCifrado == 1) {
        string kPasword;
        cin >> kPasword;
        while (getline(archivo, linea)) {
        Xor_Metod(kOperacion, linea, kPasword);
        }
    }
    if(kTipoCifrado == 2){
        int kCode;
        cin >> kCode;
        while (getline(archivo, linea)) {
            Cesar_Metod(kOperacion, linea, kCode);   
        }
    }
    archivo.close();
    return 0;
}
