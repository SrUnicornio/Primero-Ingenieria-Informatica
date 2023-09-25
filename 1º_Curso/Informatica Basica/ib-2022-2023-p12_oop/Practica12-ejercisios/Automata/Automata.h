/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Automata.h
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 27 2022
 * @brief Desarrollo de la clase Automata
 * @see https://github.com/IB-2022-2023/ib-2022-2023-p12_oop-AlvaroPerezRamos
 */
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