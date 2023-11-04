// AUTOR: 
// FECHA: 04/03/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#include <iostream>
#include <cmath>
#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3); // Se crea un racional con numerador 1 y denominador 2 y otro con numerador 3 y denominador 1

  // FASE I
  cout << "a + b: "; // Se muestra por pantalla la suma de los racionales
  (a+b).write();

  cout << "b - a: "; // Se muestra por pantalla la resta de los racionales
  (b-a).write();

  cout << "a * b: "; // Se muestra por pantalla el producto de los racionales
  (a*b).write();
  
  cout << "a / b: "; // Se muestra por pantalla la división de los racionales
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w; // Se crean dos vectores de tipo double
  v.read(), v.write(); // Se leen y muestran por pantalla los vectores
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl; // Se muestra por pantalla el producto escalar de los vectores

  vector_t<rational_t> x, y; // Se crean dos vectores de tipo rational_t
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl; // Se muestra por pantalla el producto escalar de los vectores
  
  // FASE III
  matrix_t<double> A, B, C, D, E, F, G, H, I, J, K, M; // Se crean matrices de tipo double
  A.read(), A.write(); // Se leen y muestran por pantalla las matrices
  B.read(), B.write();
  
  C.multiply(A, B); // Se multiplican las matrices A y B, se almacena en C
  cout << "Multiplicación de matrices A y B: " << endl; // Se muestra por pantalla la multiplicación de las matrices
  C.write();

/**
  D.read(), D.write(); // Se leen y muestran por pantalla las matrices
  E.read(), E.write(); 
  
  // F.sum_mat(D,E);
  // cout << "Suma de matrices D Y E: " << endl; // Se muestra por pantalla la suma de las matrices
  // F.write();

  // G.sub_mat(D,E);
  // cout << "Resta de matrices D Y E: " << endl; // Se muestra por pantalla la resta de las matrices
  // G.write();

  // H.diagonal_prin(F);
  // cout << "Diagonal principal de F: " << endl; // Se muestra por pantalla la diagonal principal de la matriz F
  // H.write();

  // I.diagonal_sec(F);
  // cout << "Diagonal secundaria de F: " << endl; // Se muestra por pantalla la diagonal secundaria de la matriz F
  // I.write();

  // J.sub_triangular_inf(G);
  // cout << "Submatriz triangular inferior de G: " << endl; // Se muestra por pantalla la submatriz triangular inferior de la matriz G
  // J.write();

  // K.sub_triangular_sup(G); // Se muestra por pantalla la submatriz triangular superior de la matriz G
  // cout << "Submatriz triangular superior de G: " << endl;
  // K.write();

  // M.traspuesta(G); // Se muestra por pantalla la traspuesta de la matriz G
  // cout << "Traspuesta de G: " << endl;
  // M.write(); */
  return 0;
}
