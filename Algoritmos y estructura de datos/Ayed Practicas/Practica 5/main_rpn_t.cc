// AUTOR: Álvaro Pérez Ramos
// FECHA: 18-04-2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Programa principal para probar la calculadora de expresiones
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// COMPILACIÓN: g++ main_rpn_t.cc -o main_rpn_t
// EJECUCIÓN:
//   ./main_rpn_t < data_rpn_t_1.txt
//   ./main_rpn_t < data_rpn_t_2.txt
//   ./main_rpn_t < data_rpn_t_3.txt

// Compilar con:
//

#include <iostream>

#include "queue_l_t.h"
#include "rpn_t.h"
#include "stack_l_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<int>> calc;
  queue_l_t<char> cola;

  while (!cin.eof()) {
    cin >> ws;  // lee los espacios en blanco
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  cout << "Expresion a evaluar: ";
  cola.write();

  int r = calc.evaluate(cola);

  cout << "Resultado: " << r << endl;

  /**
   * Modificación
   * Contar el número de pares en una pila
  */

  stack_l_t<int> modi; 

  modi.push(8);
  modi.push(2);
  modi.push(4);
  modi.push(3);
  modi.push(6);
  modi.push(3);
  cout << "El numero de pares es : " << modi.cont_pair() << endl;

  /**
   * Modificación2
   * calcular la media de una pila
  */

  stack_l_t<int> modi2;

  modi2.push(8);
  modi2.push(2);
  modi2.push(4);
  modi2.push(3);
  modi2.push(6);
  modi2.push(3);
  cout << "La media de la pila es : " << modi2.media() << endl;

  /** 
   * Modificación 3
   * Suma de los pares de una pila
  */
  stack_l_t<int> modi3;

  modi3.push(8);
  modi3.push(2);
  modi3.push(4);
  modi3.push(3);
  modi3.push(6);
  modi3.push(3);
  cout << "La suma de los pares de la pila es : " << modi3.suma_pares() << endl;

  return 0;
}
