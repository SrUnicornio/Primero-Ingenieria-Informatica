// AUTOR: Álvaro Pérez Ramos
// FECHA: 04/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); // Constructor
  ~rational_t() {} // Destructor
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const; // Devuelve el numerador
  int get_den() const; // Devuelve el denominador
  
  // setters
  void set_num(const int); // Establece el numerador
  void set_den(const int); // Establece el denominador

  double value(void) const; // Devuelve el valor real del racional
  rational_t opposite(void) const; // Devuelve el racional opuesto
  rational_t reciprocal(void) const; // Devuelve el racional reciproco

  bool is_equal(const rational_t&, const double precision = EPSILON) const; // Compara si dos racionales son iguales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // Compara si un racional es mayor que otro
  bool is_less(const rational_t&, const double precision = EPSILON) const; // Compara si un racional es menor que otro

  rational_t add(const rational_t&) const; // Suma dos racionales
  rational_t substract(const rational_t&) const; // Resta dos racionales
  rational_t multiply(const rational_t&) const; // Multiplica dos racionales
  rational_t divide(const rational_t&) const; // Divide dos racionales

  void write(ostream& os = cout) const; // Escribe el racional
  void read(istream& is = cin); // Lee el racional
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&); // Sobrecarga del operador salida
istream& operator>>(istream& is, rational_t&); // Sobrecarga del operador entrada

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); // Sobrecarga del operador suma
rational_t operator-(const rational_t&, const rational_t&); // Sobrecarga del operador resta
rational_t operator*(const rational_t&, const rational_t&); // Sobrecarga del operador multiplicación
rational_t operator/(const rational_t&, const rational_t&); // Sobrecarga del operador división
