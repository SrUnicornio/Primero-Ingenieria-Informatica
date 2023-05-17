// AUTOR: Álvaro Pérez Ramos
// FECHA: 14/01/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

using namespace std;

int main()
{
  
  rational_t a(1, 2), b(1,3), c; // Declaración de tres racionales

  cout << "a.value()= " << a.value() << endl; // Escribe el valor de a
  cout << "b.value()= " << b.value() << endl; // Escribe el valor de b
  cout << "c.value()= " << c.value() << endl; // Escribe el valor de c
  // Escribir los racionales en pantalla
  cout << "a: "; 
  a.write(); // Escribe el racional a
  cout << "b: ";
  b.write(); // Escribe el racional b
  c.read(); // Lee el racional c, desde teclado
  cout << "c: ";
  c.write(); // Escribe el racional c

  // FASE II
  rational_t x(1, 2), y(1, 3); // Declaración de dos racionales
  x.write(); // Escribe el racional x
  y.write(); // Escribe el racional y
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; // Compara x es igual que y, escribe el resultado: true o false
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Compara x es menor que y, escribe el resultado: true o false
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Compara x es mayor que y, escribe el resultado: true o false
  cout << "x == 0? " << (x.is_zero() ? "true" : "false") << endl; // Compara si x es 0, escribe el resultado: true o false
  cout << "y == 0? " << (y.is_zero() ? "true" : "false") << endl; // Compara si y es 0, escribe el resultado: true o false

  // FASE III
  cout << "a + b: ";
  a.add(b).write(); // Suma a + b, y escribe el resultado
  
  cout << "b - a: ";
  b.substract(a).write(); // Resta b - a, y escribe el resultado

  cout << "a * b: ";
  a.multiply(b).write(); // Multiplica a * b, y escribe el resultado
  
  cout << "a / b: ";
  a.divide(b).write(); // Divide a / b, y escribe el resultado

  cout << "sqrt(a): "; 
  c.root().write(); // Calcula la raíz cuadrada de a, y escribe el resultado
  
  return 0;
}

// ñ