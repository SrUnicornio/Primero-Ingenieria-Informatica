// AUTOR: 
// FECHA: 04/03/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#pragma once

#include <iostream>
#include <cassert>
#include "rational_t.hpp"

using namespace std;

template<class T>
class vector_t
{
public:
  vector_t(const int = 0); // Constructor
  ~vector_t(); // Destructor
  
  void resize(const int); // Redimensiona el vector
  
  // getters
  T get_val(const int) const; // Devuelve el valor de un elemento 
  int get_size(void) const; // Devuelve el tamaño del vector
  
  // setters
  void set_val(const int, const T); // Asigna un valor a un elemento
  
  // getters-setters
  T& at(const int); // Devuelve el elemento de la posición indicada
  T& operator[](const int); // Devuelve el elemento de la posición indicada
  
  // getters constantes
  const T& at(const int) const; // Devuelve el elemento de la posición indicada
  const T& operator[](const int) const; // Devuelve el elemento de la posición indicada

  void write(ostream& = cout) const; // Escribe el vector
  void  read(istream& = cin); // Lee el vector

  // Suma de vectores
  vector_t<T> operator+(const vector_t<T>& v) const; // Suma de vectores, con sobrecarga de operador suma

private:
  T *v_; // Vector de elementos
  int sz_; // Tamaño del vector
  
  void build(void); // Construye el vector
  void destroy(void); // Destruye el vector
};



template<class T>
vector_t<T>::vector_t(const int n) // Constructor
{ sz_ = n; // Tamaño del vector
  build(); // Llamada al método build
}



template<class T>
vector_t<T>::~vector_t() // Destructor
{
  destroy(); // Llamada al método destroy
}



template<class T>
void
vector_t<T>::build() // Construye el vector
{
  v_ = NULL; // Inicialización del vector a NULL
  if (sz_ != 0) { // Si el tamaño del vector es distinto de 0
    v_ = new T[sz_]; // Reserva de memoria para el vector
    assert(v_ != NULL); // Comprobación de que la reserva de memoria ha sido correcta
  }
}



template<class T>
void
vector_t<T>::destroy() // Destruye el vector
{
  if (v_ != NULL) { // Si el vector no es NULL
    delete[] v_; // Liberación de memoria
    v_ = NULL; // Inicialización del vector a NULL
  }
  sz_ = 0; // Inicialización del tamaño del vector a 0
}



template<class T>
void
vector_t<T>::resize(const int n) // Redimensiona el vector
{
  destroy(); // Destruye el vector
  sz_ = n; // Asigna el nuevo tamaño al vector
  build(); // Construye el vector
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const // Devuelve el valor de un elemento
{
  assert(i >= 0 && i < get_size()); // Comprobación de que el índice está dentro del rango del vector
  return v_[i]; // Devuelve el valor del elemento
}



template<class T>
inline int
vector_t<T>::get_size() const // Devuelve el tamaño del vector
{
  return sz_;
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d) // Asigna un valor a un elemento
{
  assert(i >= 0 && i < get_size()); // Comprobación de que el índice está dentro del rango del vector
  v_[i] = d; // Asigna el valor al elemento
}



template<class T>
T&
vector_t<T>::at(const int i) // Devuelve el elemento de la posición indicada
{
  assert(i >= 0 && i < get_size()); // Comprobación de que el índice está dentro del rango del vector
  return v_[i]; // Devuelve el elemento
}



template<class T>
T&
vector_t<T>::operator[](const int i) // Sobreescritura del operador []
{
  return at(i); // Devuelve el elemento
}



template<class T>
const T&
vector_t<T>::at(const int i) const // Devuelve el elemento de la posición indicada
{
  assert(i >= 0 && i < get_size()); // Comprobación de que el índice está dentro del rango del vector
  return v_[i]; // Devuelve el elemento
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const // Sobreescritura del operador []
{
  return at(i); // Devuelve el elemento
}



template<class T>
void
vector_t<T>::write(ostream& os) const // Escribe el vector
{ 
  os << get_size() << ":\t"; // Escribe el tamaño del vector
  for (int i = 0; i < get_size(); i++) // Recorre el vector
    os << at(i) << "\t"; // Escribe el elemento
  os << endl; 
}



template<class T>
void
vector_t<T>::read(istream& is)  // Lee el vector
{
  is >> sz_; // Lee el tamaño del vector
  resize(sz_); // Redimensiona el vector con el tamaño leído
  for (int i = 0; i < sz_; ++i) // Recorre el vector
    is >> at(i); // Lee el elemento
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w) // Producto escalar
{
  T prod = 0; // Inicialización del producto a 0
  for (int i = 0; i < v.get_size(); ++i) // Recorre el vector
    prod = (v.at(i)* w.at(i)) + prod; // Calcula el producto escalar de los elementos de los vectores
  return prod; // Devuelve el producto escalar
}


double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) // Producto escalar de vectores de números racionales
{
  double prod = 0; // Inicialización del producto a 0
  for (int i = 0; i < v.get_size(); ++i) { // Recorre el vector
    prod = (v.at(i).value() * w.at(i).value()) + prod; // Calcula el producto escalar de los elementos de los vectores
  }
  return prod;
}



template<class T>
vector_t<T>
vector_t<T>::operator+(const vector_t<T>& v) const // Suma de vectores, con sobrecarga de operador suma
{
  vector_t<T> sum(get_size()); // Vector suma
  for (int i = 0; i < get_size(); ++i) // Recorre el vector
    sum.set_val(i, at(i) + v.at(i)); // Calcula la suma de los elementos de los vectores
  return sum;
}
