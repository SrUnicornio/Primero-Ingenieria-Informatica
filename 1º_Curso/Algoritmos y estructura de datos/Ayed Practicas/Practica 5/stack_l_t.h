// AUTOR:
// FECHA: 18-04-2023
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}
  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;

  // modificación
  int cont_pair(); 
  double media();
  int suma_pares();

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


// operaciones
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

template<class T> const T& stack_l_t<T>::top(void) const { 
  assert(!empty());                                        
  return l_.get_head()->get_data();                       
}

template<class T> bool stack_l_t<T>::empty(void) const {  
  return l_.empty();                                       
}


// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();                      
  while (aux != NULL) {                                    
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();                                 
  }
  os << " └─────┘" << std::endl;                           
  return os;
}

//Modificación calcula el número de pares

template<class T> int stack_l_t<T>::cont_pair(){
  int par = 0;
  while(!empty()){
    int numeros = top();
    if(numeros % 2 == 0){
      par++;
    }
    pop();
  }
  cout<<endl;
  return par;
}

//Modificación calcula la media de los elementos de la pila

template<class T> double stack_l_t<T>::media(){
  int suma = 0;
  int media = 0;
  int cont = 0;
  while(!empty()){
    int numeros = top();
    suma = suma + numeros;
    cont++;
    pop();
  }
  media = suma / cont;
  cout<<endl;
  return media;
}

// Suma de los pares de una pila
template<class T> int stack_l_t<T>::suma_pares(){
  int suma = 0;
  while(!empty()){
    int numeros = top();
    if(numeros % 2 == 0){
      suma = suma + numeros;
    }
    pop();
  }
  cout<<endl;
  return suma;
}

#endif  // STACKL_H_
