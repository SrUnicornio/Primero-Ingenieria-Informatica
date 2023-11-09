
#include "Automata.h"

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  Automata automata;
  automata.Cardinal(argv[1]);
  automata.FuncionTransicion(argv[1]);
  return 0;
}
