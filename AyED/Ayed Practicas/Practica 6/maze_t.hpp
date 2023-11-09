// AUTOR:
// FECHA: 02-05-2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once 

#include <iostream>
#include "dll_t.h"         // double linked list, para la fase 3
#include "pair_t.h"     // objeto que llenará nuestra lista enlazada
#include "matrix_t.hpp"

#define TRACE(x) cout << (#x) << "= " << (x) << endl

// indica pasillo
#define PASS_ID  0
// indica pared
#define WALL_ID  1
// indica camino de salida
#define PATH_ID  2
// indica inicio del laberinto
#define START_ID 8
// indica la salida del laberinto
#define END_ID   9

// caracteres usados para mostrar el laberinto por pantalla
#define WALL_CHR  char(219)
#define PASS_CHR  " "
#define PATH_CHR  char(46)
#define START_CHR "A"
#define END_CHR   "B"

using namespace std;
using namespace AED;

typedef matrix_t<short> matrix_t_short;
typedef matrix_t<bool> matrix_t_bool;

// enumera las direcciones Norte, Este, Sur y Oeste (West)
enum direction_t {N, E, S, W};

// define vectores de desplazamiento en las 4 direcciones:
//                    N   E  S   W
const short i_d[] = { -1, 0, 1,  0};
const short j_d[] = {  0, 1, 0, -1};


class maze_t 
{
private:
  // matriz que guarda los valores leídos de la entrada
  matrix_t_short matrix_;
  // matriz que guarda si una celda ha sido visitada o no
  matrix_t_bool visited_;
  // guarda las filas y columnas de entrada (start) y salida (end)
  int i_start_, j_start_, i_end_, j_end_;

public:
  // constructor y destructor
  maze_t(void);
  ~maze_t();

  // método para resolver el laberinto y que invoca al otro método recursivo
  bool solve(dll_t<pair_t<int>>&);

  int get_m_maze() {return matrix_.get_m();}
  int get_n_maze() {return matrix_.get_n();}

  istream& read(istream& = cin);
  ostream& write(ostream& = cout) const;
  
private:
  bool is_ok_(const int, const int) const;
  bool solve_(const int, const int, dll_t<pair_t<int>>&);
};

istream& operator>>(istream&, maze_t&);
ostream& operator<<(ostream&, const maze_t&);
