// AUTOR: 
// FECHA: 02-05-2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// Se compila con:
// g++ main_maze_t.cpp maze_t.cpp -o main_maze_t

#include <iostream>
#include "maze_t.hpp"

using namespace std;

int main()
{ 
  maze_t M;
  dll_t<pair_t<int>> exit_way;
  dll_t<pair_t<int>> exit_way2;
  
  cin >> M;
  
  cout << M << endl;
  if (M.solve(exit_way)) {
    cout <<  char(173) << char(173) << "Se ha encontrado una salida estandar al laberinto !!" << endl;
    cout << M << endl << endl;
    
    dll_node_t<pair_t<int>>* aux = exit_way.get_head();
    for(int i{1}; i <= M.get_m_maze(); ++i) {
      for(int j{1}; j <= M.get_n_maze(); ++j) {
        aux = exit_way.get_head();
        while(aux != exit_way.get_tail()) {
          if(i == aux->get_data().get_val() && j == aux->get_data().get_inx()) {
            cout << PATH_CHR;
            break;
          } else {
            aux = aux->get_next();
            if(aux->get_next() == NULL) { cout << PASS_CHR; }
          }
        }
      }
      cout << endl;
    }
    cout << endl;
  } else  {
    cout << "No se ha podido encontrar la salida estandar del laberinto..." << endl;
  }
  return 0;
}
