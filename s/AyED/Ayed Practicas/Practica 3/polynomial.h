// AUTOR: 
// FECHA: 13/03/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles (vector co ceros), ej v(1, 2, 3, 0, 5)
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  // Modification
  Polynomial operator+(const Polynomial&);
  Polynomial operator-(const Polynomial&);
  Polynomial operator*(const Polynomial&);
  Polynomial operator/(const Polynomial&);
};


// Clase para polinomios basados en vectores dispersos (valor, índice), ej v(1, 2, 3, 5) 
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  // Modification
  double Eval2(const int, const double) const;
  double Eval3(const int, const double) const;
  double Eval4(const double) const;

  // Comparacion de polinomios
  bool IsGreater(const SparsePolynomial&) const;
  bool IsLess(const SparsePolynomial&) const;

  // Mostrar el polinomio mas grande de dos polinomios
  void MostrarMayor(const SparsePolynomial&) const;

  // Impresion de polinomios al reves
  void Inverse() const;

   // Mayor indice entre dos polinomios
  void MaxVal(const SparsePolynomial& spol) const;

};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
         << (i > 1      ? "x^"
             : (i == 1) ? "x"
                        : "");
      if (i > 1) os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i{0}; i < get_size(); i++){
    result += get_val(i) * pow(x, i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  // Comprobar si el tamaño de los vectores es igual
  if (get_size() != pol.get_size()) { return differents; }
  // Comprobar si los valores de los vectores son iguales
  for (int i{0}; i < get_size(); i++){
    if (fabs(get_val(i) - pol.get_val(i)) > eps) { return differents; }
  }
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
      << (inx > 1 ? "x^" : (inx == 1) ? "x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i{0}; i < get_nz(); i++){
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol,
                               const double eps) const {
  bool differents = false;
  // poner el código aquí
  int Tam_vec = 0;
  if (get_nz() != spol.get_nz()) { return differents; }
  for (int i{0}; i < get_nz(); i++){
    if (at(i).get_inx() != spol.at(i).get_inx()){ differents = true; } // Comprobar si el valor de los índices son iguales
    if (fabs(at(i).get_val() - spol.at(i).get_val()) >= eps){ differents = true; } // Comprobar si los valores son iguales
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  return IsEqual(SparsePolynomial(pol));
}

// Modificacion, operaciones de dos polinomios representados por vectores densos
Polynomial Polynomial::operator+(const Polynomial& pol) {
  // poner el código aquí
  int Tam_vec = 0;
  if (get_size() - pol.get_size() < 0){
    Tam_vec = get_size();
  }else{
    Tam_vec = pol.get_size();
  }
  double result = 0.0;
  // declarar el vector resultado
  Polynomial result_pol(Tam_vec);
  for (int i{0}; i < Tam_vec; i++){
    result = get_val(i) + pol.at(i);
    // guardar el resultado en el vector
    result_pol.set_val(i, result);
  }
  return result_pol;
}
Polynomial Polynomial::operator-(const Polynomial& pol) {
  // poner el código aquí
  int Tam_vec = 0;
  if (get_size() - pol.get_size() < 0){
    Tam_vec = get_size();
  }else{
    Tam_vec = pol.get_size();
  }
  double result = 0.0;
  // declarar el vector resultado
  Polynomial result_pol(Tam_vec);
  for (int i{0}; i < Tam_vec; i++){
    result = get_val(i) - pol.at(i);
    // guardar el resultado en el vector
    result_pol.set_val(i, result);
  }
  return result_pol;
}
Polynomial Polynomial::operator*(const Polynomial& pol) {
  // poner el código aquí
  int Tam_vec = 0;
  if (get_size() - pol.get_size() < 0){
    Tam_vec = get_size();
  }else{
    Tam_vec = pol.get_size();
  }
  double result = 0.0;
  // declarar el vector resultado
  Polynomial result_pol(Tam_vec);
  for (int i{0}; i < Tam_vec; i++){
    result = get_val(i) * pol.at(i);
    // guardar el resultado en el vector
    result_pol.set_val(i, result);
  }
  return result_pol;
}
Polynomial Polynomial::operator/(const Polynomial& pol) {
  // poner el código aquí
  int Tam_vec = 0;
  if (get_size() - pol.get_size() < 0){
    Tam_vec = get_size();
  }else{
    Tam_vec = pol.get_size();
  }
  double result = 0.0;
  // declarar el vector resultado
  Polynomial result_pol(Tam_vec);
  for (int i{0}; i < Tam_vec; i++){
    if (pol.at(i) == 0.0){ continue; }
    result = get_val(i) / pol.at(i);
    // guardar el resultado en el vector
    result_pol.set_val(i, result);
  }
  return result_pol;
}

// Resultado de la suma de los coeficientes de un polinomio a partir de un indice dado
double SparsePolynomial::Eval2(const int inx, const double x) const {
  assert(inx >= 0 && inx < get_nz());
  double result{0.0};
  for (int i{inx}; i < get_nz(); i++){
    result += at(i).get_val() * pow(x, at(i).get_inx());

    //std:: cout << "i: " << i << " result: " << result << std::Tam_vecl;
  }
  return result;
}
double SparsePolynomial::Eval3(const int inx, const double x) const {
  assert(inx >= 0 && inx < get_nz());
  double result{0.0};
  for (int i{inx}; i < get_nz(); i+=2){
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparar cual es el polinomio más grande
bool SparsePolynomial::IsGreater(const SparsePolynomial& spol) const {
  bool greater = false;
  double eps = EPS;
  // poner el código aquí
  int Tam_vec = 0;
  if (get_nz() - spol.get_nz() < 0){
    Tam_vec = get_nz();
  }else{
    Tam_vec = spol.get_nz();
  }
  if (get_nz() > spol.get_nz()){ greater = true; }
  if (get_nz() < spol.get_nz()){ greater = false; }
  return greater;
}

// Comparar cual es el polinomio más pequeño
bool SparsePolynomial::IsLess(const SparsePolynomial& spol) const {
  bool less = false;
  double eps = EPS;
  // poner el código aquí
  int Tam_vec = 0;
  if (get_nz() - spol.get_nz() < 0){
    Tam_vec = get_nz();
  }else{
    Tam_vec = spol.get_nz();
  }
  if (get_nz() < spol.get_nz()) { less = true; }
  if (get_nz() > spol.get_nz()) { less = false; }
  return less;
}

// Imprimir el polinomio al reves
void SparsePolynomial::Inverse() const {
  // poner el código aquí
  std::cout << get_n() << "(" << get_nz() << "): [ ";
  for (int i{get_nz()-1}; i >= 0; i--){
    if(i == 0){ std::cout << at(i).get_val() << " ]"; break;}
    std::cout << at(i).get_val() << "x^" << at(i).get_inx() << " + ";
  }
  std::cout << std::endl;
}

// Dado el Polinomio, suma los indices pares y resta los impares
double SparsePolynomial::Eval4(const double x) const {
  double result{0.0};
  for (int i{0}; i < get_nz(); i++){
    if (i % 2 == 0){
      result += at(i).get_val() * pow(x, at(i).get_inx());
    }else{
      result -= at(i).get_val() * pow(x, at(i).get_inx());
    }
  }
  return result;
}


#endif  // POLYNOMIAL_H_
