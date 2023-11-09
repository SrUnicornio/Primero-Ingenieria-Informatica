// AUTOR: 
// FECHA: 14/02/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t {
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const double = 0.0, const double = 1.0); //constructor, parametrizado
  ~rational_t() {} //destructor
  

  // getters
  double get_num() const; //metodo para obtener el numerador
  double get_den() const; //metodo para obtener el denominador
  
  // setters
  void set_num(const double); //metodo para modificar el numerador
  void set_den(const double); //metodo para modificar el denominador

  // value
  double value(void) const;

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const; //metodo para comparar dos racionales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; //metodo para comparar dos racionales
  bool is_less(const rational_t&, const double precision = EPSILON) const;  //metodo para comparar dos racionales
  bool is_zero(const double precision = EPSILON) const; //metodo para comparar racionales a 0
  
  // FASE III
  rational_t add(const rational_t&); //metodo para sumar dos racionales
  rational_t substract(const rational_t&); //metodo para restar dos racionales
  rational_t multiply(const rational_t&); //metodo para multiplicar dos racionales
  rational_t divide(const rational_t&); //metodo para dividir dos racionales
  rational_t root() ; //metodo para calcular la raiz cuadrada de un racional
  
  void write(ostream& = cout) const; //metodo para escribir un racional mediante tecleado
  void read(istream& = cin); //metodo para leer un racional
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  double num_, den_; //atributos privado de la clase racional_t
};
