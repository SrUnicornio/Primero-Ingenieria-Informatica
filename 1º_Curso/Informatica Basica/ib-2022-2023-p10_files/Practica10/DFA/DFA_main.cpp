#include "DFA_fun.h"

int main(int argc, char *argv[]) {
    Usage(argc, argv);
    string fichero = argv[1];
    Cardinal(fichero);
    FuncionTransicion(fichero);
    return 0;
}