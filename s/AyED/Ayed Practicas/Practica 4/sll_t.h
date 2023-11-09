// AUTOR:
// FECHA: 30/03/2023
// EMAIL:
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}                                                // constructor por defecto

  // destructor
  ~sll_t(void);                                                               // destructor

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };                      // obtiene el primer nodo
  
  bool empty(void) const;                                                     // comprueba si la lista está vacía

  // operaciones
  void push_front(sll_node_t<T>*);                                            // inserta un nodo al principio
  sll_node_t<T>* pop_front(void);                                             // extrae el primer nodo

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);                          // inserta un nodo después de otro
  sll_node_t<T>* erase_after(sll_node_t<T>*);                                 // extrae un nodo después de otro

  void push_back(sll_node_t<T>*);                                             // inserta un nodo al final
  sll_node_t<T>* pop_back(void);                                              // extrae el último nodo

  sll_node_t<T>* search(const T&) const;                                      // busca un nodo por su dato

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;                       // escribe la lista

 private:                                                                     // atributos privados
  sll_node_t<T>* head_;                                                       // puntero al primer nodo
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {                                                          // mientras no esté vacía
    sll_node_t<T>* aux = head_;                                               // nodo auxiliar para no perder la referencia
    head_ = head_->get_next();                                                // avanzar el puntero
    delete aux;                                                               // borrar el nodo auxiliar
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {                         // comprueba si la lista está vacía
  return head_ == NULL;                                                       // si el puntero al primer nodo es NULL, la lista está vacía
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {              // inserta un nodo al principio
  assert(n != NULL);                                                          // comprobar que el nodo no es NULL

  n->set_next(head_);                                                         // establecer el siguiente nodo del nuevo nodo como el primer nodo
  head_ = n;                                                                  // establecer el nuevo nodo como el primer nodo
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) {                 // extrae el primer nodo
  assert(!empty());                                                           // comprobar que la lista no está vacía
  sll_node_t<T>* aux = head_;                                                 // nodo auxiliar para no perder la referencia
  head_ = head_->get_next();                                                  // avanzar el puntero
  aux->set_next(NULL);                                                        // establecer el siguiente nodo del nodo auxiliar como NULL

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev, 
                                              sll_node_t<T>* n) {             // inserta un nodo después de otro
  assert(prev != NULL && n != NULL);                                          // comprobar que los nodos no son NULL

  n->set_next(prev->get_next());                                              // establecer el siguiente nodo del nuevo nodo como el siguiente nodo del nodo previo
  prev->set_next(n);                                                          // establecer el siguiente nodo del nodo previo como el nuevo nodo
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) {// extrae un nodo después de otro
  assert(!empty());                                                           // comprobar que la lista no está vacía
  assert(prev != NULL);                                                       // comprobar que el nodo previo no es NULL
  sll_node_t<T>* aux = prev->get_next();                                      // nodo auxiliar para no perder la referencia
  
  assert(aux != NULL);                                                        // comprobar que el nodo auxiliar no es NULL
  prev->set_next(aux->get_next());                                            // establecer el siguiente nodo del nodo previo como el siguiente nodo del nodo auxiliar
  aux->set_next(NULL);                                                        // establecer el siguiente nodo del nodo auxiliar como NULL

  return aux;
}

template <class T> void sll_t<T>::push_back(sll_node_t<T>* n) {               // inserta un nodo al final
  assert(n != NULL);                                                          // comprobar que el nodo no es NULL

  if (empty())                                                                // si la lista está vacía
    head_ = n;                                                                // establecer el nuevo nodo como el primer nodo
  else {                                                                      // si la lista no está vacía
    sll_node_t<T>* aux = head_;                                               // nodo auxiliar para no perder la referencia
    while (aux->get_next() != NULL)                                           // mientras el siguiente nodo del nodo auxiliar no sea NULL
      aux = aux->get_next();                                                  // avanzar el puntero
    aux->set_next(n);                                                         // establecer el siguiente nodo del nodo auxiliar como el nuevo nodo
  }
}

template <class T> sll_node_t<T>* sll_t<T>::pop_back(void) {                  // extrae el último nodo
  assert(!empty());                                                           // comprobar que la lista no está vacía
  sll_node_t<T>* aux = head_;                                                 // nodo auxiliar para no perder la referencia

  if (aux->get_next() == NULL) {                                              // si el siguiente nodo del nodo auxiliar es NULL
    head_ = NULL;                                                             // establecer el puntero al primer nodo como NULL
    aux->set_next(NULL);                                                      // establecer el siguiente nodo del nodo auxiliar como NULL
  } else {                                                                    // si el siguiente nodo del nodo auxiliar no es NULL
    while (aux->get_next()->get_next() != NULL)                               // mientras el siguiente nodo del siguiente nodo del nodo auxiliar no sea NULL
      aux = aux->get_next();                                                  // avanzar el puntero
    sll_node_t<T>* aux2 = aux->get_next();                                    // nodo auxiliar 2 para no perder la referencia
    aux->set_next(NULL);                                                      // establecer el siguiente nodo del nodo auxiliar como NULL
    aux2->set_next(NULL);                                                     // establecer el siguiente nodo del nodo auxiliar 2 como NULL
    aux = aux2;                                                               // establecer el nodo auxiliar 2 como el nodo auxiliar
  }

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {        // busca un nodo por su dato
  sll_node_t<T>* aux = head_;                                                 // nodo auxiliar para no perder la referencia
  while ((aux != NULL) && (aux->get_data() != d))                             // mientras el nodo auxiliar no sea NULL y el dato del nodo auxiliar no sea igual al dato buscado
    aux = aux->get_next();                                                    // avanzar el puntero  
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {    // escribe la lista
  sll_node_t<T>* aux = head_;                                                 // nodo auxiliar para no perder la referencia

  while (aux != NULL) {                                                       // mientras el nodo auxiliar no sea NULL
    aux->write(os);                                                           // escribir el nodo auxiliar
    aux = aux->get_next();                                                    // avanzar el puntero al siguiente nodo
  }
  return os;
}

#endif  // SLLT_H_
