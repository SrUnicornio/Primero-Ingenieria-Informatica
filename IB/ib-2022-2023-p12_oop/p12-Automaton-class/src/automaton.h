/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 22 2021
 * @brief Automato class Declaration
 *        Models a Finite State Automaton
 * @see https://en.wikipedia.org/wiki/Deterministic_finite_automaton
 */

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <string>
#include <vector>

#include "state.h"

/**
 * Clase Automaton
 * @brief Represents a DFA
 */
class Automaton {
 public:
  Automaton(const std::string& automaton_file_name);
  void Print() const;
 private:
  bool IsInAlphabet(const char symbol) const;
  bool IsInAccepting(const int state) const;
  
  int number_of_states_{};
  int initial_state_{};
  std::vector<State> states_{};
  std::vector<int> accepting_states_{};
  std::vector<char> alphabet_{};
};

#endif
