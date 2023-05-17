/*
*  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
*
*
*  Autores : Antonio Sedeno Noda, Sergio Alonso
*  Cursos   : 2012-2021
*/

#include "grafo.h"
#include <stack>

void GRAFO::destroy() {
  for (unsigned i=0; i< n; i++)
    {
    LS[i].clear();
    A[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    };
  }
  LS.clear();
  LP.clear();
  A.clear();

}

void GRAFO::build(char nombrefichero[85], int &errorapertura){
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if(textfile.is_open()) {
    unsigned i, j, k;
    // leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
    textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
    // los nodos internamente se numeran desde 0 a n-1
    // creamos las n listas de sucesores
    LS.resize(n);
    A.resize(n);
    if(dirigido == 1)
      LP.resize(n); // Si tenemos n nodos, la primera dimensión de LS y LP debe tener n espacios
          // leemos los m arcos
    for (k=0;k<m;k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      //damos los valores a dummy.j y dummy.c
      //situamos en la posicion del nodo i a dummy mediante push_backM
      //pendiente de hacer un segundo push_back si es no dirigido. O no.
      //pendiente la construccion de LP, si es dirigido
      //pendiente del valor a devolver en errorapertura
      dummy.j = j - 1; // resto a j una unidad, para tener el nodo 1, en la posición cero, el 2 en la 1, etc...
      if(dirigido == 0) // Si es no dirigido, solo tenemos que trabajar con LS
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        if((i-1) != (j-1)) {
          LS[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo que le precede, y el coste del camino
          // Como es un grafo no dirigido, se ponen todos los datos en LS pero reflejados con la diagonal principal
        }
      }
      if(dirigido == 1) // No pongo un else, por si hay acaso, dirigido != 0 y dirigido !=1
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        LP[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LP, el nodo que le precede, y el coste del camino
        // Como es un grafo dirigido, usamos LP para colocar este dato
        
      }
    }
  }
  textfile.close();
}

void GRAFO::ListaPredecesores(){}

GRAFO::~GRAFO() { destroy();}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) { build (nombrefichero, errorapertura); }

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
  //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
  destroy();
  //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo() {
  cout << endl << "El Grafo cargado actualmente tiene las siguiente características:" << endl;
  cout << "Nº de Nodos: " << n << endl;
  cout << "Nº de Arcos: " << m << endl;
  cout << "¿Grafo Dirigido? " << (dirigido == 1 ? " Si" : " No");
  cout << endl << endl;
}

void Mostrar_Lista(const vector<LA_nodo>& L, unsigned& nodos) {
  for(int i{0}; i < nodos; ++i) {
    cout << "[" << i + 1 << "]";
    if(L[i].size() == 0) 
      cout << " : NULL";
    for(int k{0}; k < L[i].size(); ++k) {
      cout << " :  " << L[i][k].j + 1 << "(" << L[i][k].c << ") ";
    }
    cout << endl;
  }
  cout << L[0][0].j << endl;
  cout << endl;
}

void GRAFO::Mostrar_Listas(int l) {
  if(l == 1 || l == 0)
    Mostrar_Lista(LS, n); // Para Grafos Dirigidos y No Dirigidos   
  if(l == -1)
    Mostrar_Lista(LP, n); // Para Grafos Dirigidos
}

void GRAFO::bfs_num(unsigned i, vector<LA_nodo> L, vector<unsigned> &pred, vector<unsigned> &d) {
  vector<bool> visitado; // Vector de visitados
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0); // Vector de predecesores y distancia
  d.resize(n, 0);
  pred[i] = i;
  d[i] = 0;

  queue<unsigned> cola; // Cola de nodos
  cola.push(i); // Inicializamos la cola con el nodo inicial

  while (!cola.empty()) { // Mientras la cola no esté vacía
    unsigned k = cola.front(); // Tomamos el primer elemento de la cola
    cola.pop(); // Lo sacamos de la cola
    for (unsigned j{0}; j < L[k].size(); ++j) { // Recorremos los nodos adyacentes a k+1
      if(visitado[L[k][j].j] == false) { // Si no ha sido visitado
        visitado[L[k][j].j] = true;   // Lo visitamos
        cola.push(L[k][j].j);         // Lo metemos en la cola
        pred[L[k][j].j] = k;          // Le asignamos predecesores
        d[L[k][j].j] = d[k] + 1;      // Le calculamos la distancia
      }
    }
  }
}

void GRAFO::RecorridoAmplitud() {
  vector<unsigned> pred;    // Declaramos el vector de nodos predecesores, la posición es el vector actual, y el número que contiene es su predecesor
  vector<unsigned> d;       // Declaramos el vector de etiquetas distancia, la posición es el nodo, y el número que contenga, es la distancia del nodo elegido por el usuario
  int nodo_inicial{0};

  cout << "\nElige el nodo inicial en el rango [1 - " << n << "]: ";
  cin >> nodo_inicial;

  while (nodo_inicial < 1 || nodo_inicial > n){
    cout << "El nodo elegido no está en el rango [1 - " << n << "], elige otro: ";
    cin >> nodo_inicial;
  }
  
  cout << "Nodo inicial elegido [" << nodo_inicial << "]" << endl << endl;

  bfs_num(nodo_inicial - 1, LS, pred, d);
  cout << "Distancia entre el nodo inicial y el resto, expresado en el número de arcos" << endl << endl;

  for(int i{0}; i < d.size(); ++i) { // Recorremos el vector de distancias para mostrar los nodos a distancia i
    cout << "[" << i + 1 << "] : " << d[i] << endl;
    cout << endl;
  }

  // Mostramos los predecesores
  cout << endl << "Predecesores de cada nodo" << endl << endl;
  for(int i{0}; i < pred.size(); ++i) {
    cout << "Predecesor de " << i + 1 << " : ";
      cout << pred[i]+1 << endl;
  }
  cout << endl;
}

void GRAFO::PredecesoresRecursivos(int s,int i,LA_nodo pred) {
  if(i != s) {// nodo inicial != nodo predecesor?
    PredecesoresRecursivos(s, pred[i].j, pred);
    std::cout << " => " <<  i + 1;
  } else {std::cout << s + 1;}
}

void GRAFO::FloydWarshall() //Algoritmo de FW para caminos mínimos entre cualquier par de nodos;
{
  std::vector<LA_nodo> P; //Usaremos la misma estructura de datos de LS para guardar P y D

  //Inicializamos P y D en P
  //Creamos P
  P.resize(n); //Ya tenemos las posiciones P[0] a P[n-1]
  for (unsigned i{0}; i < n; ++i) P[i].resize(n); //Ya tenemos la matriz cuadrada
  for (unsigned i{0}; i < n; ++i) {
  for (unsigned j{0}; j < n; ++j) {
    if (i != j) {// Inicialización base
      P[i][j].j = -1; //en el campo .j ponemos el predecesor
      P[i][j].c = maxint; //en el campo .c ponemos el coste
    } else {// Inicializamos los bucles
      P[i][j].c = 0; //El coste en el caso de un bucle
      P[i][j].j = i; //El predecesor en el caso de un bucle
    }
  }
  }
  //Recorremos LS para inicializar P, su predecesor en .j y su distancia en .c
  for (unsigned i{0}; i < n; ++i) {
    for (unsigned j{0}; j < LS[i].size(); ++j) {
        P[i][LS[i][j].j].j = i;
        P[i][LS[i][j].j].c = LS[i][j].c;
    }
  }
  //Con las matrices ya inicializadas, vamos ahora a realizar las k comparativas...
  //Bien, ya tenemos D y P, mostremos las matrices y los caminos mínimos...

  for (int i{0}; i < n; ++i) {
  std::cout << "(";
  for (int j{0}; j < n; ++j) {
    if(P[i][j].c == maxint) {
      std::cout << "  inf";
    } else {
      std::cout << "  " << P[i][j].c;
    }
  }
  std::cout << "  )\n";
}
std::cout << "   Costes" << std::endl << std::endl;

  for (int i{0}; i < n; ++i) {
    std::cout << "(";
    for (int j{0}; j < n; ++j) {
      std::cout << "  " << P[i][j].j + 1;
    }
    std::cout << "  )\n";
  }
  std::cout << "   Predecesores" << std::endl;
  std::cout << " Matrices inicializadas\n\n\n";
  
  // Bucle de n fases
  for (unsigned k{0}; k < n; ++k) {
    for (unsigned i{0}; i < n; ++i) {
      if (i != k) {
        for (unsigned j{0}; j < n; ++j) {
          if (j != k) {
            if ((P[i][k].c != maxint) && (P[k][j].c != maxint)) {
              if (P[i][j].c > (P[i][k].c + P[k][j].c)) {
                P[i][j].c = P[i][k].c + P[k][j].c;
                P[i][j].j = P[k][j].j;
              }
            }
          }
        }
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    std::cout << "(";
    for (int j{0}; j < n; ++j) {
      if(P[i][j].c == maxint) {
        std::cout << "  inf";
      } else { 
        std::cout << "  " << P[i][j].c;
      }
    }
    std::cout << "  )\n";
  }
  std::cout << "   Costes" << std::endl << std::endl;

  for (int i{0}; i < n; ++i) {
    std::cout << "(";
    for (int j{0}; j < n; ++j)
      std::cout << "  " << P[i][j].j + 1;
    std::cout << "  )\n";
  }
  std::cout << "   Predecesores\n";
  std::cout << "Matrices tras usar el método FW\n\n";

  std::cout << "Ahora se mostrarán todos los caminos posibles para\n";
  std::cout << "cada par de nodos 'i' y 'j', así como su coste:\n\n";

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if ((i == j) && (P[i][j].c != 0)) {// si fila == columna y además el coste de la posición es != 0
        std::cout << "El nodo " << i + 1 << " está dentro de un ciclo de coste negativo | Coste Total: " << P[i][j].c << std::endl;
        continue;
      }

      std::cout << "Camino mínimo del nodo " << i + 1 << " al " << j + 1 << ": ";
      if (P[i][j].c != maxint) {// Si coste != infinito, es un camino válido
        PredecesoresRecursivos(i,j,P[i]); // llamamos a la función recursiva
        std::cout << "  | Coste Total: " << P[i][j].c << std::endl;
      } else {std::cout << "NULL" << "\n";}
    }
    std::cout << "\n\n";
  }
  std::cout << "\n";
}

//Ejecuta el algoritmo de Prim y muestra el árbol por pantalla

void GRAFO::AlgoritmoDePrim() {
  int T{0};
  vector<bool> M(n, false); // vector de nodos marcados
  vector<int> coste(n, maxint); // vector de costes 
  vector<unsigned> pred(n, 0); // vector de predecesores
  int costeTotal{0}; // coste total del árbol
  unsigned u{0}; // nodo actual

  std::cout << LS[0][0].j << std::endl;

  std::cout << "Algoritmo de Prim" << std::endl;
  std::cout << "Elige un nodo inicial (1 - " << n << "): ";
  std::cin >> u;
  std::cout << "Iniciamos desde el nodo : " << u << std::endl;
  u--; // decrementamos el nodo inicial para que coincida con el vector

  coste[0] = 0; // el costo del primer nodo es 0
  costeTotal = 0; // inicializamos el costo total en 0

  while (T < n) {
    for (unsigned i{0}; i < LS[u].size(); ++i) {
      if (M[LS[u][i].j] == false && LS[u][i].c < coste[LS[u][i].j]) {
          coste[LS[u][i].j] = LS[u][i].c;
          pred[LS[u][i].j] = u;
      }
    }

    int min{maxint};
    for (unsigned i{0}; i < n; ++i) {
      if (M[i] == false && coste[i] < min) {
          min = coste[i];
          u = i;
        
      }
    }
    
    M[u] = true;
    T++;

  }

  for (unsigned i{0}; i < n; ++i) {
    if (coste[i] != maxint) {
      std::cout << "Nodo " << pred[i] + 1 << " -> Nodo " << i + 1 << " | Coste: " << coste[i] << std::endl;
      costeTotal += coste[i];
    }
  }

  std::cout << "Costo total: " << costeTotal << std::endl;

}

//Ejecuta el algoritmo de disjktra y muestra el camino mínimo entre dos nodos
void GRAFO::Dijkstra_(double &comparaciones, unsigned s)
{
  cout << "Soluciones:" << endl;
  vector<bool> PermanentementeEtiquetado; //Almacén de nodos permanentemente etiquetados
  vector<int> d; //Etiquetas distancia
  vector<unsigned> pred; //Predecesores
  int min; //Etiqueta distancia mínima
  unsigned candidato; //Candidato a ser permanentemente etiquetado

  //Inicialmente no hay ningun nodo permanentemente etiquetado
  PermanentementeEtiquetado.resize(n,false);
  //Inicialmente todas las etiquetas distancias son infinito
  d.resize(n,maxint);
  //Inicialmente el pred es null
  pred.resize(n,UERROR);
  //La etiqueta distancia del nodo origen es 0, y es su propio pred
  d[s]=0; pred[s]=s; comparaciones = 0;

  do {
  //Buscamos un nodo candidato a ser permanentemente etiquetado: aquel de entre los no permanentemente etiquetados, es decir,  en el almacén con menor etiqueta distancia no infinita.
  //Si existe ese candidato, lo etiquetamos permanentemente y usamos  los arcos de la lista de sucesores para buscar atajos. Por cada comparación  realizada para buscar atajos, incrementamos el contador de comparaciones.
  //Si no existe ese candidato, es que ya hemos etiquetado permanentemente todos los nodos alcanzables desde el origen, y por tanto hemos acabado.
  
  //Inicializamos el mínimo a infinito
  min = maxint;
  //Inicializamos el candidato a UERROR
  candidato = UERROR;
  //Buscamos el candidato
  for (unsigned i=0; i<n; i++) {
    if (!PermanentementeEtiquetado[i] && d[i] < min) {
      min = d[i];
      candidato = i;
    }
  }
  //Si el candidato es UERROR, es que no hay candidato, y por tanto hemos acabado
  if (candidato == UERROR) break;
  //Si no, lo etiquetamos permanentemente
  PermanentementeEtiquetado[candidato] = true;

  //Y buscamos atajos
  for (unsigned i=0; i<LS[candidato].size(); i++) {
    if (d[LS[candidato][i].j] > d[candidato] + LS[candidato][i].c) {
      d[LS[candidato][i].j] = d[candidato] + LS[candidato][i].c;
      pred[LS[candidato][i].j] = candidato;
    }
    comparaciones++;
  }
  //Esto lo hacemos mientras haya candidatos
  } while (candidato != UERROR);
  
  //En esta parte del código, mostramos los caminos mínimos para cada nodo si los hay.
  for (unsigned i=0; i<n; i++) {
      if (i != s) {
        if (d[i] == maxint) {
          cout << "No hay camino desde " << s+1 << " hasta " << i+1 << endl;
        } else {
          cout << "El camino desde " << s+1 << " hasta " << i+1 << " es: ";
          for (unsigned j=i; j!=s; j=pred[j]) {
            cout << j+1;
            if (pred[j] != s) cout << " - ";
          }
          cout << " y su longitud es " << d[i] << endl;
        }
      }
    }
  }

// Para el grafo siguiente
// 6 10 1
// 1 2 3
// 1 3 2
// 2 4 1
// 2 5 3
// 2 6 2
// 3 2 1
// 3 6 3
// 5 3 2
// 5 4 1
// 6 5 0

  //Ejecuta el algoritmo de Bellman-Ford y muestra el camino mínimo entre dos nodos
void GRAFO::BellmanFordEnd_(double &comparaciones, unsigned s) {
  vector<int> d; // etiquetas distancia
  vector<unsigned> pred; // predecesores
  unsigned numeromejoras = 0; // numero de mejoras
  bool mejora; // si hay mejora

  //Idem que en el algoritmo de Dijkstra
  d.resize(n,maxint);
  pred.resize(n,UERROR);
  d[s]=0; pred[s]=s; comparaciones = 0;
  do {
  // recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i] + cij, y actualizamos d y pred, incrementando el contador comparaciones cuando comparamos, independientemente de si mejoramos o no.
  //si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos terminado; contabilizamos los bucles en los que ha habido mejoras
  mejora = false;
  for (unsigned i=0; i<n; i++) {
    for (unsigned j=0; j<LS[i].size(); j++) {
      if (d[LS[i][j].j] > d[i] + LS[i][j].c) {
        d[LS[i][j].j] = d[i] + LS[i][j].c;
        pred[LS[i][j].j] = i;
        mejora = true;
      }
      comparaciones++;
    }
  }
  numeromejoras++;
  } while ((numeromejoras < n) && (mejora == true));
  //para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos realizado n+1 veces la relajacion con mejora; si mejora es false, pues tenemos solucion
  //Mostramos los caminos mínimos que se puedan haber encontrado, o advertimos de la existencia de un ciclo de coste negativo.
  if (mejora == true) {
    cout << "Hay un ciclo de coste negativo" << endl;
  } else {
    cout << "Soluciones:" << endl;
    // No hay camino desde 2 al nodo 1
    // El camino desde 2 al nodo 3 es: 2 - 6 -5 - 3 y su longitud es 4
    // El camino desde 2 al nodo 4 es: 2 - 4y su longitud es 1
    // El camino desde 2 nodo 5 es: 2 - 6 - 5 y su longitud es 2
    // El camino desde 2 hasta 6 es: 2 - 6 y su longitud es 2

    for (unsigned i=0; i<n; i++) {
      if (i != s) {
        if (d[i] == maxint) {
          cout << "No hay camino desde " << s+1 << " hasta " << i+1 << endl;
        } else {
          cout << "El camino desde " << s+1 << " hasta " << i+1 << " es: ";
          for (unsigned j=i; j!=s; j=pred[j]) {
            cout << j+1;
            if (pred[j] != s) cout << " - ";
          }
          cout << " y su longitud es " << d[i] << endl;
        }
      }
    }
  }
}

//Comapra los algoritmos de Dijkstra y Bellman-Ford
void GRAFO::ComparativaCM(){
  double comparacionesDijkstra, comparacionesBellmanFord;
  int s;
  cout << "Introduce el nodo [1, " << n << "]: ";
  cin >> s;
  Dijkstra_(comparacionesDijkstra, s-1);
  cout << "Comparaciones Dijkstra: " << comparacionesDijkstra << endl;
  BellmanFordEnd_(comparacionesBellmanFord, s-1);
  cout << "Comparaciones Bellman-Ford: " << comparacionesBellmanFord << endl;

  cout << "El algoritmo de Dijkstra es " << comparacionesBellmanFord/comparacionesDijkstra << " veces más rápido que el de Bellman-Ford" << endl;
}