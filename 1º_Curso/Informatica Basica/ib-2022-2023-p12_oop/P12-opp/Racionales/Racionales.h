#include <iostream>
using namespace std;

#ifndef RACIONALES_H
#define RACIONALES_H

class Racionales {
 public:
  Racionales();
  Racionales(int numerador, int denominador);
  void Inverso();
 private:
  int numerador_;
  int denominador_;
};

#endif

/**
 *@brief Constructor por defecto
 *@param numerador_
 *@param denominador_
 */
Racionales::Racionales() {
  numerador_ = 0;
  denominador_ = 0;
}

/**
 *@brief Constructor por defecto
 *@param numerador_
 *@param denominador_
 */
Racionales::Racionales(int numerador, int denominador) {
  numerador_ = numerador;
  denominador_ = denominador;
}

/**
 *@brief Metodo para calcular el inverso de un numero racional
 *@param numerador_
 *@param denominador_
 */
void Racionales::Inverso() {
  int auxiliar = numerador_;
  numerador_ = denominador_;
  denominador_ = auxiliar;
    cout << "El inverso del numero racional es: " << numerador_ << "/" << denominador_ << endl;
}
