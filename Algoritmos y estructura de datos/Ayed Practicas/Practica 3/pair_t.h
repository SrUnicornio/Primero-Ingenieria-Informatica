// AUTOR: Álvaro Pérez Ramos
// FECHA: 13/03/2023
// EMAIL: alu010157402@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T val_;
  int inx_;
};


template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {} // constructor por defecto

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {} // constructor por parámetros

template<class T> pair_t<T>::~pair_t() {} // destructor

template<class T> void pair_t<T>::set(T val, int inx) { // setter
  val_ = val;
  inx_ = inx;
}

template<class T> int pair_t<T>::get_inx() const { // getter
  return inx_;
}

template<class T> T pair_t<T>::get_val() const { // getter
  return val_; 
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) { // lectura
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const { // escritura
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) { // sobrecarga del operador <<
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
