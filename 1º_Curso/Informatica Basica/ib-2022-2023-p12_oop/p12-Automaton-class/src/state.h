/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 22 2021
 * @brief State class declaration
 *        A state models a finite state automaton
 */

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <cassert>

#include "transition.h"

/**
 * Clase State
 * @brief Represents an automaton state
 */
class State {
 public:
   void AddTransition(const Transition& transition) {
     // ... 
   }
   Transition GetTransition(const int index) const {
     // ... 
   }
 private:
   int label_{0};
   bool is_final_{false};
   int number_of_transitions_{0};
   std::vector<Transition> transitions_{};
};


#endif
