#include "Racionales.h"

/**
  *@brief Constructor por defecto
  *@param numerador
  *@param denominador
*/
Racionales::Racionales(int numerador, int denominador) {
    numerador_ = numerador;
    denominador_ = denominador;
}

/**
  *@brief Suma de dos racionales
  *@param racional1
  *@param racional2
*/
void Racionales::Suma(Racionales racional1, Racionales racional2) {
    int numerador = racional1.numerador_ * racional2.denominador_ + racional2.numerador_ * racional1.denominador_;
    int denominador = racional1.denominador_ * racional2.denominador_;
    cout << "La suma de los racionales es: " << numerador << "/" << denominador << endl;
}

/**
  *@brief Resta de dos racionales
  *@param racional1
  *@param racional2
*/
void Racionales::Resta(Racionales racional1, Racionales racional2) {
    int numerador = racional1.numerador_ * racional2.denominador_ - racional2.numerador_ * racional1.denominador_;
    int denominador = racional1.denominador_ * racional2.denominador_;
    cout << "La resta de los racionales es: " << numerador << "/" << denominador << endl;
}

/**
  *@brief Multiplicacion de dos racionales
  *@param racional1
  *@param racional2
*/
void Racionales::Multiplicacion(Racionales racional1, Racionales racional2) {
    int numerador = racional1.numerador_ * racional2.numerador_;
    int denominador = racional1.denominador_ * racional2.denominador_;
    cout << "La multiplicacion de los racionales es: " << numerador << "/" << denominador << endl;
}

/**
  *@brief Division de dos racionales
  *@param racional1
  *@param racional2
*/

void Racionales::Division(Racionales racional1, Racionales racional2) {
    int numerador = racional1.numerador_ * racional2.denominador_;
    int denominador = racional1.denominador_ * racional2.numerador_;
    cout << "La division de los racionales es: " << numerador << "/" << denominador << endl;
}

/**
  *@brief Destructor
*/
Racionales::~Racionales() {
}