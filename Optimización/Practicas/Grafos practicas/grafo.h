/*
 *  GRAFO.h - plantilla para los alumnos y alumnas de definicion de la clase GRAFO
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos  : 2012-2021
 */

#ifndef _GRAPH_H
#define _GRAPH_H


#include <vector>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const unsigned UERROR = 65000; //Para ciertos algoritmos es necesario codificar este valor de error
const int maxint = 1000000; //Para ciertos algoritmos es necesario codificar este valor de m�ximo

// definicion de un elemento de la lista de adyacencia

typedef struct {
	unsigned j; // nodo
	int      c; // atributo para expresar los costes, pesos, las longitudes, las inversiones, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo
typedef vector<ElementoLista> LA_nodo;

class GRAFO
 {
	unsigned            dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	unsigned            n;         // numero de NODOS
	unsigned            m;         // numero de ARCOS
	vector<LA_nodo>     LS;        // Lista de adyacencia de los sucesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño
	vector<LA_nodo>     LP;        // Lista de adyacencia de los predecesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño
	vector<LA_nodo>     A;         // Matriz de adyacencia, tanto adyacencia como costes
	void destroy();                // Destructor del LS, A, y LP, en su caso
	void build (char nombrefichero[85], int &errorapertura); //Crea LS, A y LP en su caso, desde la lectura del fichero
	void dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind); //Recorrido en profundidad recursivo con recorridos enum y postnum
  void bfs_num(unsigned i, vector<LA_nodo>  L, vector<unsigned> &pred, vector<unsigned> &d); //Recorrido en amplitud con c�lculo de pred y d
public:
  GRAFO(char nombrefichero[], int &errorapertura);
  void actualizar(char nombrefichero[], int &errorapertura);
  unsigned Es_dirigido(); // devuelve 0 si el grafo es no dirigido y 1 si es dirigido
  void Info_Grafo(); // devuelve informacion basica del grafo
  void Mostrar_Listas(int l);  //Muestra la lista de adyacencia
  void Mostrar_Matriz(); //Muestra la matriz de adyacencia: nodos y costes
  void ListaPredecesores(); //Recorre la lista de sucesores LS para construir la de predecesores, LP
  void RecorridoProfundidad(); //Construye un recorrido en profundidad desde un nodo inicial
  void RecorridoAmplitud(); //Construye un recorrido en amplitud desde un nodo inicial
  ~GRAFO(); //Destructor del objeto grafo

  void FloydWarshall(); //Ejecuta el método de FW y muestra las matrices por pantalla
  void PredecesoresRecursivos(int s,int i,LA_nodo pred); // Función que nos ayuda a encontrar los caminos mínimos en el método de arriba
  void AlgoritmoDePrim(); //Ejecuta el algoritmo de Prim y muestra el árbol por pantalla

  void Dijkstra_(double &comparaciones, unsigned s); //Ejecuta el algoritmo de Dijsktra y muestra el árbol por pantalla
  void BellmanFordEnd_(double &comparaciones, unsigned s); //Ejecuta el algoritmo de BellmanFord y muestra el árbol por pantalla

  void ComparativaCM(); //Ejecuta los algoritmos de Dijsktra y BellmanFord y muestra el árbol por pantalla
};

// 

#endif