// AUTOR: Álvaro Pérez Ramos
// FECHA: 30/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLL_NODET_H_
#define SLL_NODET_H_

#include <iostream>

// Clase para nodos de listas enlazadas
template <class T> class sll_node_t {
 public:
  // constructores
  sll_node_t(void) : data_(), next_(NULL) {}  // constructor por defecto
  sll_node_t(const T& data) : data_(data), next_(NULL) {} // constructor de copia

  // destructor
  ~sll_node_t(void) {}; // destructor

  // getters & setters
  sll_node_t<T>* get_next(void) const { return next_; } // obtiene el siguiente nodo
  void set_next(sll_node_t<T>* next) { next_ = next; }  // establece el siguiente nodo

  const T& get_data(void) const { return data_; } // obtiene el dato
  void set_data(const T& data) { data_ = data; } // establece el dato

  // E/S
  std::ostream& write(std::ostream& = std::cout) const; // escribe el dato

 private: // atributos privados
  T data_; // dato
  sll_node_t<T>* next_; // puntero al siguiente nodo
};


// E/S
template <class T> std::ostream& sll_node_t<T>::write(std::ostream& os) const  { // escribe el dato
  os << data_;
  return os;
}

#endif  // SLL_NODET_H_
