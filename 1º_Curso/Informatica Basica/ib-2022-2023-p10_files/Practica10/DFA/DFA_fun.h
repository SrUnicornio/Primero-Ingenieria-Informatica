#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const string kHelperText = "Este programa lee un fichero con \
        especificacion sobre un automata finito determinista.";
void Usage(int argc, char *argv[]);

void Cardinal(const string fichero);

void FuncionTransicion(const string fichero);