// AUTOR: Álvaro Pérez Ramos
// FECHA: 13/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <cassert>
#include <iostream>

template <class T>
class vector_t {
 public:
  // constructores
  vector_t(const int = 0);
  vector_t(const vector_t&);  // constructor de copia

  // operador de asignación
  vector_t<T>& operator=(const vector_t<T>&);

  // destructor
  ~vector_t();

  // getters
  T get_val(const int) const;
  int get_size(void) const;

  // setters
  void set_val(const int, const T);

  // getters-setters
  T& at(const int);
  T& operator[](const int);

  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void resize(const int);

  // E/S
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;

 private:
  T* v_;
  int sz_;

  void build(void);
  void destroy(void);
};

template <class T>
vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

// constructor de copia
template <class T>
vector_t<T>::vector_t(const vector_t<T>& w) : v_(NULL), sz_(0) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
template <class T>
vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++) at(i) = w.at(i);

  return *this;
}

template <class T>
vector_t<T>::~vector_t() { // destructor
  destroy();
}

template <class T>
void vector_t<T>::build() { // construye el vector
  v_ = NULL; 
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T>
void vector_t<T>::destroy() { // destruye el vector
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T>
void vector_t<T>::resize(const int n) { // redimensiona el vector
  destroy();
  sz_ = n;
  build();
}

template <class T>
inline T vector_t<T>::get_val(const int i) const { // devuelve el valor de la posición i
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
inline int vector_t<T>::get_size() const { // devuelve el tamaño del vector
  return sz_;
}

template <class T>
void vector_t<T>::set_val(const int i, const T d) { // asigna el valor d a la posición i
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template <class T>
T& vector_t<T>::at(const int i) { // devuelve la referencia al valor de la posición i
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
T& vector_t<T>::operator[](const int i) { // devuelve la referencia al valor de la posición i
  return at(i);
}

template <class T>
const T& vector_t<T>::at(const int i) const { // devuelve la referencia constante al valor de la posición i
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
const T& vector_t<T>::operator[](const int i) const { // devuelve la referencia constante al valor de la posición i
  return at(i);
}

template <class T>
void vector_t<T>::read(std::istream& is) { // lee el vector desde el flujo de entrada is
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++) is >> at(i);
}

template <class T>
void vector_t<T>::write(std::ostream& os) const { // escribe el vector en el flujo de salida os
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template <class T>
std::istream& operator>>(std::istream& is, vector_t<T>& v) { // Sobrecarga del operador de entrada
  v.read(is);
  return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) { // Sobrecarga del operador de salida
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
