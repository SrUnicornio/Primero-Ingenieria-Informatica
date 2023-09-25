#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void Usage(int argc, char *argv[]);
void Encoding(string cadena);
void Decoding(string cadena);
void Cesar_Metod(char kOperador, string line, int code);
void Xor_Metod(char kOperator, string frase, string pasword);