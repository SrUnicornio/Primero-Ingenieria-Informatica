// AUTOR: Álvaro Pérez Ramos
// FECHA: 04/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0);  // Constructor
  ~matrix_t(); // Destructor
  
  void resize(const int, const int); // Redimensiona la matriz
  
  // getters
  int get_m(void) const; // Devuelve el número de filas
  int get_n(void) const; // Devuelve el número de columnas
  
  // getters-setters
  T& at(const int, const int); // Devuelve el elemento de la posición (i, j)
  T& operator()(const int, const int); // Sobreescritura del operador () para devolver el elemento de la posición (i, j)
  
  // getters constantes
  const T& at(const int, const int) const; // Devuelve el elemento de la posición (i, j)
  const T& operator()(const int, const int) const; // Sobreescritura del operador () para devolver el elemento de la posición (i, j)
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); //Método que multiplica dos matrices
  /**void sum_mat(const matrix_t<T>&, const matrix_t<T>&); //Método que suma dos matrices
  void sub_mat(const matrix_t<T>&, const matrix_t<T>&); //Método que resta dos matrices
  void diagonal_prin(const matrix_t<T>&); //Método que calcula la diagonal principal de una matriz
  void diagonal_sec(const matrix_t<T>&); //Método que calcula la diagonal secundaria de una matriz
  void sub_triangular_inf(const matrix_t<T>&); //Método que calcula la submatriz triangular inferior de una matriz 
  void sub_triangular_sup(const matrix_t<T>&); //Método que calcula la submatriz triangular superior de una matriz
  void traspuesta(const matrix_t<T>&); //Método que calcula la matriz traspuesta de una matriz */

  void write(ostream& = cout) const; // Escribe la matriz
  void read(istream& = cin); // Lee la matriz

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_; // Vector de elementos
  
  int pos(const int, const int) const; // Devuelve la posición del elemento (i, j)
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n) // Constructor
{ 
  m_ = m; // Asigna el número de filas
  n_ = n; // Asigna el número de columnas
  v_.resize(m_ * n_); // Redimensiona el vector
}



template<class T>
matrix_t<T>::~matrix_t() // Destructor
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n) // Redimensiona la matriz
{
  assert(m > 0 && n > 0); // Comprueba que las dimensiones son correctas
  m_ = m; // Asigna el número de filas
  n_ = n; // Asigna el número de columnas
  v_.resize(m_ * n_); // Redimensiona el vector
}



template<class T>
inline int
matrix_t<T>::get_m() const // Devuelve el número de filas
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const // Devuelve el número de columnas
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j) // Devuelve el elemento de la posición (i, j)
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j) // Devuelve el elemento de la posición (i, j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const // Devuelve el elemento de la posición (i, j)
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return v_[pos(i, j)];
}



template<class T>
const T& 
matrix_t<T>::operator()(const int i, const int j) const // Devuelve el elemento de la posición (i, j)
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl; // Escribe el número de filas y columnas
  for (int i = 1; i <= get_m(); ++i) { 
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is) // Lee una matriz
{
  is >> m_ >> n_; // Lee el número de filas y columnas
  resize(m_, n_); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const // Devuelve la posición de la matriz
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) // Multiplica dos matrices
{
  assert (A.get_n() == B.get_m()); // Comprueba que el número de columnas de A es igual al número de filas de B
  matrix_t c(A.get_n(), B.get_m()); // Crea una matriz de tamaño (filas de A, columnas de B)
  resize(A.get_m(), B.get_n()); // Redimensiona la matriz
  for (int i=1; i <= A.get_m();i++)
    for (int j=1; j <= B.get_n(); j++){
      at(i,j) = 0;
      for(int k=1; k <= B.get_m(); k++)
        at(i,j) = at(i,j) + (A(i,k)*B(k,j));
    }
}

/**
template<class T>
void
matrix_t<T>::sum_mat(const matrix_t<T>& D, const matrix_t<T>& E) // Suma dos matrices
{
  assert (D.get_m()*D.get_n() == E.get_m()*E.get_n()); // Comprueba que las matrices tienen el mismo tamaño
  matrix_t F(D.get_n(), D.get_m()); // Crea una matriz de tamaño (filas de D, columnas de D)
  resize(D.get_n(), D.get_m()); // Redimensiona la matriz
  for(int i = 1; i <= get_m(); i++)
    for(int j = 1; j <= get_n(); j++)
      at(i,j) = D(i,j) + E(i,j);
}

template<class T>
void
matrix_t<T>::sub_mat(const matrix_t<T>& D, const matrix_t<T>& E) // Resta dos matrices
 {
  assert (D.get_m()*D.get_n() == E.get_m()*E.get_n()); // Comprueba que las matrices tienen el mismo tamaño
  matrix_t F(D.get_n(), D.get_m()); // Crea una matriz de tamaño (filas de D, columnas de D)
  resize(D.get_n(), D.get_m()); // Redimensiona la matriz
  for(int i = 1; i <= get_m(); i++) 
    for(int j = 1; j <= get_n(); j++)
      at(i,j) = D(i,j) - E(i,j);
}

template<class T>
void
matrix_t<T>::diagonal_prin(const matrix_t<T>& F) // Calcula la diagonal principal
{
  assert(F.get_m() == F.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t H(F.get_m(), F.get_n()); // Crea una matriz de tamaño (filas de F, columnas de F)
  resize (F.get_m(), F.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_n(); i++)
    at(i,i) = F(i,i);
}

template<class T>
void
matrix_t<T>::diagonal_sec(const matrix_t<T>& F) // Calcula la diagonal secundaria
{
  assert(F.get_m() == F.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t I(F.get_m(), F.get_n()); // Crea una matriz de tamaño (filas de F, columnas de F)
  resize (F.get_m(), F.get_n()); // Redimensiona la matriz
  for (int i = 1, j = get_m(); i <= get_m(); i++,j--)
    at(i,j) = F(i,j);
}

template<class T>
void
matrix_t<T>::sub_triangular_inf(const matrix_t<T>& G) // Calcula la supmatriz triangular inferior
{
  assert(G.get_m() == G.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t J(G.get_m(), G.get_n()); // Crea una matriz de tamaño (filas de G, columnas de G)
  resize (G.get_m(), G.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); i++) 
    for (int j = 1; j <= i; j++)
      at(i,j) = G(i,j);
}

template<class T>
void
matrix_t<T>::sub_triangular_sup(const matrix_t<T>& G) // Calcula la submatriz triangular superior
{ 
  assert(G.get_m() == G.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t K(G.get_m(), G.get_n()); // Crea una matriz de tamaño (filas de G, columnas de G)
  resize (G.get_m(), G.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); i++)
    for (int j = i; j <= get_m(); j++)
      at(i,j) = G(i,j);
}


// Traspone la matriz
template<class T>
void
matrix_t<T>::traspuesta(const matrix_t<T>& A) // Calcula la traspuesta de una matriz
{
  resize(A.get_n(), A.get_m()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); ++i) // Recorre las filas de la matriz resultado
    for (int j = 1; j <= get_n(); ++j) // Recorre las columnas de la matriz resultado
      at(i, j) = A(j, i); // Guarda el resultado en la matriz resultado, de la posición (i, j) correspondiente
}
*/