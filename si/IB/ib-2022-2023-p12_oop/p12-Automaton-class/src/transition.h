/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 22 2021
 * @brief Transition class declaration
 *        Models a state transition in a Finite State Automaton
 */

#ifndef TRANSITION_H
#define TRANSITION_H

/**
 * Clase Transition
 * @brief Represents an automaton transition
 *        A transition has two data members: 
 *           1) symbol and 
 *           2) destination state
 */
class Transition {
 public:
 private:
  char symbol_{};
  int destination_state_{};
};


#endif
