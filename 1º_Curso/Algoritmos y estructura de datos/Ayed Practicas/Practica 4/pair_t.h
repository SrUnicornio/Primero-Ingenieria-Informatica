// AUTOR:
// FECHA: 30/03/2023
// EMAIL:
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); // constructor por defecto
  pair_t(T, int); // constructor de copia

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const; // obtiene el valor
  int get_inx(void) const; // obtiene el índice
  void set(T, int); // establece el valor e índice

  // E/S
  std::istream& read(std::istream& is = std::cin); // lee el valor e índice
  std::ostream& write(std::ostream& os = std::cout) const; // escribe el valor e índice

 private: // atributos privados
  T val_; // valor
  int inx_; // índice
};


template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {} // constructor por defecto, inx = -1 porque trabajamos con vectores

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {} // constructor de copia

template<class T> pair_t<T>::~pair_t() {} // destructor

template<class T> void pair_t<T>::set(T val, int inx) { // establece el valor e índice
  val_ = val; // establece el valor
  inx_ = inx; // establece el índice
}

template<class T> int pair_t<T>::get_inx() const { // obtiene el índice
  return inx_;
}

template<class T> T pair_t<T>::get_val() const { // obtiene el valor
  return val_;
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) { // lee el valor e índice
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const { // escribe el valor e índice
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os, 
					   const pair_t<T>& p) { // sobrecarga del operador <<, para escribir el valor e índice
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
