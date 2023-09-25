#include <fstream>
#include <iostream>
#include <string>
#include "Vowels-and-Consonants_fun.h"
using namespace std;

int main(int argc, char *argv[]) {
    Usage(argc, argv);
    string fichero = argv[1];
    PalabraLarga(fichero);
   }