#include "Text-vowelmax.h"
using namespace std;

int main(int argc, char *argv[]) {
    Usage(argc, argv);
    string fichero = argv[1];
    PalabraMasVocales(fichero);
}