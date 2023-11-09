
#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const string kHelperText = "Este programa lee un fichero con \
        especificacion sobre un automata finito determinista.";
void Usage(int argc, char *argv[]);

#ifndef AUTOMATA_H
#define AUTOMATA_H

class Automata {
  public:
    Automata();
    ~Automata();
    void Cardinal(const string fichero);
    void FuncionTransicion(const string fichero);
  private:
    int numero_estados, estado_arranque;
    string estados_aceptados;
    string estado;
};

#endif /* AUTOMATA_H */
