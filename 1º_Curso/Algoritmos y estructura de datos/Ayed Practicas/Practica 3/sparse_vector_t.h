// AUTOR:
// FECHA: 13/03/2023
// EMAIL:
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <math.h>  // fabs

#include <iostream>

#include "pair_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t; // typedef para simplificar el código
typedef vector_t<pair_double_t> pair_vector_t; // typedef para simplificar el código

class sparse_vector_t {
 public:
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&,
                  const double = EPS);      // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);

  // destructor
  ~sparse_vector_t();

  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);

  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;
  
  // Modification
  void Modificacion(const int numero);
  // Funcion para mostrar los valores a partir de un indice
  void MostrarValores(const int numero);
  void MostrarValores2(const int numero);
  // Resultado de la suma de los coeficientes de un polinomio a partir de un indice dado
  double SumaCoeficientes(const int numero);
  // Muestra los indices del vector
  void MostrarIndices();
  // Mostrar el valor mayor de un vector y su indice
  void Mayor();
  // Mostrar el valor menor de un vector y su indice
  void Menor();

 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};

bool IsNotZero(const double val, const double eps = EPS) { return fabs(val) > eps; } // función auxiliar


sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {} // constructor por defecto

// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) // constructor normal
    : pv_(), nz_(0), n_(0) {
  // poner el código aquí
  n_ = v.get_size();
  for (int i = 0; i < n_; i++) {
    if (v.at(i) != 0) {
      nz_++;
    }
  }

  pv_.resize(nz_);

  for (int i = 0, p = 0; i < n_; i++) {
    if (v.at(i) != 0) {
      pair_double_t aux(v.get_val(i), i);
      pv_.at(p) = aux;
      p++;
    }
  }
}

// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz(); // se invoca directamente al getter
  n_ = w.get_n();  // se invoca directamente al getter
  pv_ = w.pv_; // se invoca directamente al operator=

  return *this;
}

sparse_vector_t::~sparse_vector_t() {} // destructor

inline int sparse_vector_t::get_nz() const { return nz_; } // getters

inline int sparse_vector_t::get_n() const { return n_; } // getters

pair_double_t& sparse_vector_t::at(const int i) { // getters-setters
  assert(i >= 0 && i < get_nz()); // comprobación de rango
  return pv_[i];
}

pair_double_t& sparse_vector_t::operator[](const int i) { return at(i); } // sobre carga del operador []

const pair_double_t& sparse_vector_t::at(const int i) const { // getters constantes
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

const pair_double_t& sparse_vector_t::operator[](const int i) const { // sobre carga del operador []
  return at(i);
}

// E/S
void sparse_vector_t::write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++) os << pv_[i] << " ";
  os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) { // sobre carga del operador <<
  sv.write(os);
  return os;
}

// Modificación
void sparse_vector_t::Modificacion(const int numero) {
  for (int i = 0; i < get_nz(); i++){
    int contador=0;
    
    if(numero == pv_[i].get_inx()){
    std::cout<< pv_[i].get_val()<< " x^" << pv_[i].get_inx()<<std::endl;
    }
  }  

  bool haynumero = false;
  for (int j = 0; j < get_nz(); j++) {
    if (numero != pv_[j].get_inx()) {
      haynumero = true;
    } else{
      haynumero = false;
      break;
    }
  }if(haynumero){
  std::cout << 0 << std::endl;
  }
}

// Funcion para mostrar los valores a partir de un indice
void sparse_vector_t::MostrarValores(const int numero) {
  assert(numero >= 0 && numero < get_n());
  std::cout << get_n() << "(" << get_nz() << ") = " << "[ ";
  for (int i = numero; i < get_nz(); i++) {
    std::cout << pv_[i].get_val() << " x^" << pv_[i].get_inx();
    if (i != get_nz() - 1) {
      std::cout << " + ";
    }
  }
  std::cout << " ]" << std::endl;
}

// Funcion para mostrar los valores a partir de un indice solo los de indice par o impar dependiendo del numero que le pasemos
void sparse_vector_t::MostrarValores2(const int numero) {
  assert(numero >= 0 && numero < get_n());
  std::cout << get_n() << "(" << get_nz() << ") = " << "[ ";
  for (int i = numero; i < get_nz(); i += 2) {
      std::cout << pv_[i].get_val() << " x^" << pv_[i].get_inx();
      if (numero%2 == 0){
        if (i != get_nz() - 1) {std::cout << " + ";}
      }
      else{
        if (i != get_nz() - 2) {std::cout << " + ";}
      }
    }
  std::cout << " ]" << std::endl;
}

// Muestra los indices del vector
void sparse_vector_t::MostrarIndices() {
  std::cout << get_n() << "(" << get_nz() << ") = " << "[ ";
  for (int i = 0; i < get_nz(); i++) {
    std::cout << pv_[i].get_inx();
    if (i != get_nz() - 1) {
      std::cout << " , ";
    }
  }
  std::cout << " ]" << std::endl;
}

// Mostrar el valor mayor de un vector y su indice
void sparse_vector_t::Mayor() {
  double mayor = pv_[0].get_val();
  int indice = 0;
  for (int i = 0; i < get_nz(); i++) {
    if (pv_[i].get_val() > mayor) {
      mayor = pv_[i].get_val();
      indice = pv_[i].get_inx();
    }
  }
  std::cout << "El mayor es: " << mayor << " y su pocicion es: " << indice << std::endl;
}

// Mostrar el valor menor de un vector y su indice
void sparse_vector_t::Menor() {
  double menor = pv_[0].get_val();
  int indice = 0;
  for (int i = 0; i < get_nz(); i++) {
    if (pv_[i].get_val() < menor) {
      menor = pv_[i].get_val();
      indice = pv_[i].get_inx();
    }
  }
  std::cout << "El menor es: " << menor << " y su pocicion es: " << indice << std::endl;
}
#endif  // SPARSE_VECTORT_H_
