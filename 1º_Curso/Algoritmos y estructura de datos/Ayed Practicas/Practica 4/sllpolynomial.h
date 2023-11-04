// AUTOR: 
// FECHA: 30/03/2023
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>
#include <algorithm>  // reverse

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;           // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t(){};                                    // constructor por defecto
  SllPolynomial(const vector_t<double>&, const double = EPS);         // constructor de copia

  // destructor
  ~SllPolynomial(){};                                                 // destructor

  // E/S
  void Write(std::ostream& = std::cout) const;                        // escribe el polinomio

  // operaciones
  double Eval(const double) const;                                    // evaluación del polinomio en x
  bool IsEqual(const SllPolynomial&, const double = EPS) const;       // comparación de polinomios, con tolerancia EPS
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS); // suma de polinomios, con tolerancia EPS
  // Modificación 
  void Impar(SllPolynomial& modi);                                    // Saber si es impar o par, con tolerancia EPS
  void Sub(const SllPolynomial&, SllPolynomial&, const double = EPS); // resta de polinomios, con tolerancia EPS
  void Sum2(const SllPolynomial&, SllPolynomial&, const double = EPS);// suma de polinomios, con tolerancia EPS
  void RemoveFirstLast(SllPolynomial&);                               // Elimina el primer y ultimo elemento
  int eval_par(const double num);                                     // Evalua el polinomio en los indices pares
  void ordenar(SllPolynomial&);                                       // Ordena el polinomio de mayor a menor segun su coeficiente
};

bool IsNotZero(const double val, const double eps = EPS) { return fabs(val) > eps; }

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  // poner el código aquí
  for (int i = v.get_size() - 1; i >= 0; i--) {           // Recorremos el vector de forma inversa
    if (IsNotZero(v.at(i), eps)) {                        // Comprobamos si el valor es distinto de cero
      pair_double_t pair(v.get_val(i), i);                // Creamos el pair_double_t, para tener valor e indice
      SllPolyNode* aux = new SllPolyNode(pair);           // Creamos el nodo
      push_front(aux);                                    // Añadimos el nodo a la lista
    }
  }
}

// E/S
void SllPolynomial::Write(std::ostream& os) const {       // Escribe el polinomio
  os << "[ ";
  bool first{true};                                       // Para saber si es el primer elemento
  SllPolyNode* aux{get_head()};                           // Creamos un auxiliar para recorrer la lista
  while (aux != NULL) {                                   // Mientras no lleguemos al final de la lista
    int inx{aux->get_data().get_inx()};                   // Obtenemos el indice
    double val{aux->get_data().get_val()};                // Obtenemos el valor
    if (val > 0)                                          // si el valor es positivo se escribe con signo +
      os << (!first ? " + " : "") << val;
    else                                                  // si el valor es negativo se escribe con signo -
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1) os << inx;                               // si el indice es mayor que 1 se escribe el indice
    first = false;                                        // Ya no es el primer elemento
    aux = aux->get_next();                                // Avanzamos al siguiente nodo
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) { // Sobrecarga del operador <<, para poder escribir el polinomio
  p.Write(os);
  return os;
}

// Operaciones con polinomios
// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  SllPolyNode* aux(get_head());                           // Creamos un auxiliar para recorrer la lista

  while (aux != NULL) {                                   // Mientras no lleguemos al final de la lista
    int index(aux->get_data().get_inx());                 // Obtenemos el indice
    double val(aux->get_data().get_val());                // Obtenemos el valor
    result = result + val * pow(x, index);                // Calculamos el resultado
    aux = aux->get_next();                                // Avanzamos al siguiente nodo
  }
  return result;
}

//  Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  SllPolyNode* aux(get_head());                           // Creamos un auxiliar para recorrer la lista, del primer polinomio
  SllPolyNode* second_aux(sllpol.get_head());             // Creamos un auxiliar para recorrer la lista del segundo polinomio

  while (aux != NULL && second_aux != NULL) {             // Mientras no lleguemos al final de la lista
    int index(aux->get_data().get_inx());                 // Obtenemos el indice del primer polinomio
    double val(aux->get_data().get_val());                // Obtenemos el valor del primer polinomio
    int segundo_inx(second_aux->get_data().get_inx());    // Obtenemos el indice del segundo polinomio
    double segundo_val(second_aux->get_data().get_val()); // Obtenemos el valor del segundo polinomio

    if (index != segundo_inx && val != segundo_val) {     // Si los indices o los valores son distintos
      return differents; 
    }
    aux = aux->get_next();                                // Avanzamos al siguiente nodo del primer polinomio
    second_aux = second_aux->get_next();                  // Avanzamos al siguiente nodo del segundo polinomio
  }
  if (aux != NULL || second_aux != NULL) {                // Si alguno de los dos polinomios tiene mas elementos devuelvo false
    return differents;
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {
  // poner el código aquí
  SllPolynomial auxSllPolSum;                             // Creamos un polinomio auxiliar
  SllPolyNode* aux = get_head();                          // Creamos un auxiliar para recorrer la lista, del primer polinomio
  SllPolyNode* aux2 = sllpol.get_head();                  // Creamos un auxiliar para recorrer la lista del segundo polinomio
  pair_double_t pair;                                     // Creamos un pair_double_t para guardar el valor e indice
  double sum = 0.0;

  // si tienen los mismos exponentes se suman
  while (aux != NULL || aux2 != NULL) {                   // Mientras no lleguemos al final de la lista
    if (aux != NULL && aux2 != NULL) {                    // Si los dos polinomios igual tamaño
      if (aux->get_data().get_inx() == aux2->get_data().get_inx()) {  // Si los indices son iguales
        sum = aux->get_data().get_val() + aux2->get_data().get_val(); // Sumamos los valores
        if (IsNotZero(sum, eps)) {                        // Si la suma no es 0
          pair.set(sum, aux->get_data().get_inx());       // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair)); // Guardamos el pair en el polinomio auxiliar
        }
        if (aux != NULL) aux = aux->get_next();          // Avanzamos al siguiente nodo del primer polinomio
        if (aux2 != NULL) aux2 = aux2->get_next();       // Avanzamos al siguiente nodo del segundo polinomio
      } else if (aux->get_data().get_inx() > aux2->get_data().get_inx()) { // Si el indice del primer polinomio es mayor
        sum = aux2->get_data().get_val();                // Guardamos la suma del segundo polinomio
        if (IsNotZero(sum, eps)) {                       // Si la suma no es 0  
          pair.set(sum, aux2->get_data().get_inx());     // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }
        if (aux2 != NULL) aux2 = aux2->get_next();       // Avanzamos al siguiente nodo del segundo polinomio
      } else {
        sum = aux->get_data().get_val();                 // Guardamos la suma del primer polinomio
        if (IsNotZero(sum, eps)) {                       // Si la suma no es 0
          pair.set(sum, aux->get_data().get_inx());      // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }

        if (aux != NULL) aux = aux->get_next();          // Avanzamos al siguiente nodo del primer polinomio
      }
                                                         // Si alguno de los dos polinomios esta vacio
    } else if (aux == NULL) {                            // Si el primer polinomio esta vacio
      sum = aux2->get_data().get_val();                  // Guardamos la suma del segundo polinomio
      if (IsNotZero(sum, eps)) {                         // Si la suma no es 0
        pair.set(sum, aux2->get_data().get_inx());       // Guardamos la suma e indice en el pair
        auxSllPolSum.push_front(new SllPolyNode(pair));  // Guardamos el pair en el polinomio auxiliar
      }
      if (aux2 != NULL) aux2 = aux2->get_next();         // Avanzamos al siguiente nodo del segundo polinomio

    } else if (aux2 == NULL) {                           // Si el segundo polinomio esta vacio
      sum = aux->get_data().get_val();                   // Guardamos la suma del primer polinomio
      if (IsNotZero(sum, eps)) {                         // Si la suma no es 0
        pair.set(sum, aux2->get_data().get_inx());       // Guardamos la suma e indice en el pair
        auxSllPolSum.push_front(new SllPolyNode(pair));  // Guardamos el pair en el polinomio auxiliar
      }

      if (aux != NULL) aux = aux->get_next();            // Avanzamos al siguiente nodo del primer polinomio
    }
  }

  while (!auxSllPolSum.empty()) {                        // Mientras el polinomio auxiliar no este vacio
    sllpolsum.push_front(auxSllPolSum.pop_front());      // Guardamos el polinomio auxiliar en el polinomio suma
  }
}

// Modificación
// Imprimir los monomios de grado impar
void SllPolynomial::Impar(SllPolynomial& modi){
  SllPolynomial auxSllPolModi;                            // Creamos un polinomio auxiliar
  SllPolyNode* aux = get_head();                          // Creamos un auxiliar para recorrer la lista, del primer polinomio
  pair_double_t pair;                                     // Creamos un pair_double_t para guardar el valor e indice

  while (aux != NULL) {                                   // Mientras no lleguemos al final de la lista
    if (aux->get_data().get_inx() % 2 != 0) {             // Si el indice es impar
      pair.set(aux->get_data().get_val(), aux->get_data().get_inx()); // Guardamos el valor e indice en el pair
      auxSllPolModi.push_front(new SllPolyNode(pair));    // Guardamos el pair en el polinomio auxiliar
    }
    aux = aux->get_next();                                // Avanzamos al siguiente nodo del primer polinomio
  }

  while (!auxSllPolModi.empty()) {                        // Mientras el polinomio auxiliar no este vacio
    modi.push_front(auxSllPolModi.pop_front());           // Guardamos el polinomio auxiliar en el polinomio suma
  }
}


// Generar nuevo polinomio resta del polinomio invocante menos otro polinomio
void SllPolynomial::Sub(const SllPolynomial& sllpol, SllPolynomial& sllpolsub, const double eps) {
  // poner el código aquí
  SllPolynomial auxSllPolSub;                            // Creamos un polinomio auxiliar
  SllPolyNode* aux = get_head();                         // Creamos un auxiliar para recorrer la lista, del primer polinomio
  SllPolyNode* aux2 = sllpol.get_head();                 // Creamos un auxiliar para recorrer la lista del segundo polinomio
  pair_double_t pair;                                    // Creamos un pair_double_t para guardar el valor e indice
  double sub = 0.0;

  // si tienen los mismos exponentes se restan
  while (aux != NULL || aux2 != NULL) {                  // Mientras no lleguemos al final de la lista
    if (aux != NULL && aux2 != NULL) {                   // Si los dos polinomios igual tamaño
      if (aux->get_data().get_inx() == aux2->get_data().get_inx()) {  // Si los indices son iguales
        sub = aux->get_data().get_val() - aux2->get_data().get_val(); // Restamos los valores
        if (IsNotZero(sub, eps)) {                       // Si la resta no es 0
          pair.set(sub, aux->get_data().get_inx());      // Guardamos la resta e indice en el pair
          auxSllPolSub.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }
        if (aux != NULL) aux = aux->get_next();          // Avanzamos al siguiente nodo del primer polinomio
        if (aux2 != NULL) aux2 = aux2->get_next();       // Avanzamos al siguiente nodo del segundo polinomio
      } else if (aux->get_data().get_inx() > aux2->get_data().get_inx()) { // Si el indice del primer polinomio es mayor
        sub = -aux2->get_data().get_val();                // Guardamos la resta del segundo polinomio
        if (IsNotZero(sub, eps)) {
          pair.set(sub, aux2->get_data().get_inx());     // Guardamos la resta e indice en el pair
          auxSllPolSub.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }
        if (aux2 != NULL) aux2 = aux2->get_next();       // Avanzamos al siguiente nodo del segundo polinomio
      } else {                                           // Si el indice del segundo polinomio es mayor
        sub = -aux->get_data().get_val();                 // Guardamos la resta del primer polinomio
        if (IsNotZero(sub, eps)) {                       // Si la resta no es 0
          pair.set(sub, aux->get_data().get_inx());      // Guardamos la resta e indice en el pair
          auxSllPolSub.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }

        if (aux != NULL) aux = aux->get_next();          // Avanzamos al siguiente nodo del primer polinomio
      }
                                                         // Si uno de dos polinomios esta vacio
    } else if (aux == NULL) {                            // Si el primer polinomio esta vacio
        sub = aux2->get_data().get_val();                // Guardamos la resta del segundo polinomio
        if (IsNotZero(sub, eps)) {                       // Si la resta no es 0
          pair.set(sub, aux2->get_data().get_inx());     // Guardamos la resta e indice en el pair
          auxSllPolSub.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }
        if (aux2 != NULL) aux2 = aux2->get_next();       // Avanzamos al siguiente nodo del segundo polinomio

      } else if (aux2 == NULL) {                         // Si el segundo polinomio esta vacio
        sub = aux->get_data().get_val();                 // Guardamos la resta del primer polinomio
        if (IsNotZero(sub, eps)) {                       // Si la resta no es 0
          pair.set(sub, aux->get_data().get_inx());      // Guardamos la resta e indice en el pair
          auxSllPolSub.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }

        if (aux != NULL) aux = aux->get_next();          // Avanzamos al siguiente nodo del primer polinomio
      }
    }
  while (!auxSllPolSub.empty()) {                        // Mientras el polinomio auxiliar no este vacio
    sllpolsub.push_front(auxSllPolSub.pop_front());      // Guardamos el polinomio auxiliar en el polinomio suma
  }
}

// quitar el primer y el ultimo nodo de una lista simplemente enlazada
void SllPolynomial::RemoveFirstLast(SllPolynomial& new_sllpol){ //Metodo para recortar el polinomio
  SllPolyNode* auxiliar = get_head();
  auxiliar = auxiliar -> get_next();
  SllPolyNode* auxiliar2 = auxiliar;
  auxiliar2 = auxiliar2 -> get_next();
  pair_double_t par;
  SllPolynomial pol_aux;
  while(auxiliar != NULL){
    auxiliar2 = auxiliar2 -> get_next();
    double coeficiente = auxiliar -> get_data().get_val();
    par.set(coeficiente, auxiliar -> get_data().get_inx());
    pol_aux.push_front(new SllPolyNode(par));
    auxiliar = auxiliar -> get_next();
    if(auxiliar2 == NULL){
      auxiliar = NULL;
    }
  }
  while(!pol_aux.empty()){
    new_sllpol.push_front(pol_aux.pop_front());
  }
}

int SllPolynomial::eval_par(const double num){
  double suma = 0;
  SllPolyNode* auxiliar = get_head();  
  while(auxiliar != NULL){
    double coeficiente = auxiliar -> get_data().get_val();
    int exponente = auxiliar -> get_data().get_inx();
    if(exponente % 2 == 0){
      suma = suma + coeficiente*pow(num,exponente);
    }
    auxiliar = auxiliar -> get_next();
  }
  return suma;
}

// Ordena el polinomio de mayor a menor segun su coeficiente
void SllPolynomial::ordenar(SllPolynomial& sllordenado) {
  SllPolyNode* aux = get_head();
  SllPolyNode* aux2 = get_head();
  vector_t<pair_double_t> vector_ord;

  int tam = 0;

  while (aux != NULL) {
    tam++;
    aux = aux->get_next();
  }

  vector_ord.resize(tam);

  for (int i = 0; i < tam; i++) {
    vector_ord[i] = aux2->get_data();
    aux2 = aux2->get_next();
  }

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam - 1; j++) {
      if (vector_ord[j].get_val() < vector_ord[j + 1].get_val()) {
        pair_double_t aux = vector_ord[j];
        vector_ord[j] = vector_ord[j + 1];
        vector_ord[j + 1] = aux;
      }
    }
  }

  for (int i = 0; i < tam; i++) {
    sllordenado.push_front(new SllPolyNode(vector_ord[i]));
  }
}



#endif  // SLLPOLYNOMIAL_H_
