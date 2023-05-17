 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"


void menu (unsigned dirigido, char &opcion) { //Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
  cout << "Optimizacion en Grafos, 2020-2021 Alvaro Perez Ramos" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
  if (dirigido == 0) {//Grafo no dirigido
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
    cout << "r  Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
    cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
    cout << "p. Mostrar arbol generador minimo coste, [P]rim" << endl;
  } else {// Grafo Dirigido
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "e. Mostrar la lista de pr[e]decesores del grafo" << endl;
    cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "d. Caminos minimos: [d]ijkstra" << endl;
    cout << "f. Caminos minimos: [f]loyd-Warshall" << endl;
    cout << "v. Dijkstra [v]s Bellman-Ford" << endl;
  };
  cout << "q. Finalizar el programa" << endl;
  cout << "Introduce la letra de la accion a ejecutar  > ";
  cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un menu inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
  int error_apertura;
  char nombrefichero[85], opcion;
  //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
    cout << "Introduce el nombre completo del fichero de datos" << endl;
    cin >> nombrefichero;
  };
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    system ("cls");
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
    system("pause");
    system("cls");
  } else {
    system("cls");
    cout<< endl << "Grafo cargado desde el fichero " << nombrefichero << endl << endl;
    system("pause");
    system("cls");
    do {
      menu(G.Es_dirigido(), opcion);
      cout << endl;
      switch (opcion) {
        case 'q': break;
        case 'c':
        system("cls");
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            system ("cls");
            cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
            system("pause");
            system("cls");
          } else {
            system("cls");
            cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
            system("pause");
            system("cls");
          };
          break;
        case 'i':
          system("cls");
          cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo();
          system("pause");
          system("cls");
          break;
        case 'y': // Mostrar matriz de adyacencia del grafo, no hacerlo
          system("cls");
            cout << endl << "Opción no disponible en este programa" << endl << endl;
            system("pause");
            system("cls");
          break;
        case 'm': // Recorrido en amplitud, hacerlo
          system("cls");
          G.RecorridoAmplitud();
          system("pause");
          system("cls");
          break;
        case 'r': // Recorrido en profundidad, no hacer
          system("cls");
          cout << endl << "Opción no disponible en este programa" << endl << endl;
          system("pause");
          system("cls");
          break;

        if(G.Es_dirigido() == 0) {// Si es un grafo no dirigido
          case 'a': // Mostrar lista de adyacencia del grafo, hacerlo
            system("cls");
            cout << "La lista de adyacencia del grafo " << nombrefichero;
            cout << " es:" << endl << endl;
            G.Mostrar_Listas(0);
            system("pause");
            system("cls");
            break;
          case 'o': // Mostrar componentes conexas del grafo
            system("cls");
            cout << endl << "Opción no disponible en este programa" << endl << endl;
            system("pause");
            system("cls");
            break;
          case 'p': // Mostrar arbol generador minimo coste, Prim
            system("cls");
            G.AlgoritmoDePrim();
            system("pause");
            system("cls");
            break;
        } else {// Si es un grafo dirigido
          case 's': // Mostrar lista de sucesores del grafo, hacerlo
            system("cls");
            cout << "La lista de sucesores del grafo " << nombrefichero;
            cout << " es:" << endl << endl;
            G.Mostrar_Listas(1);
            system("pause");
            system("cls");
            break;
          case 'e': // Mostrar lista de predecesores del grafo, hacerlo
            system("cls");
            cout << "La lista de predecesores del grafo " << nombrefichero;
            cout << " es:" << endl << endl;
            G.Mostrar_Listas(-1);
            system("pause");
            system("cls");
            break;
          case 'd': // Caminos minimos, dilkstra, no hacerlo
            system("cls");
            cout << endl << "Opción no disponible en este programa" << endl << endl;
            system("pause");
            system("cls");
            break;
          case 'f': // Caminos minimos, floyd-warhall
            system("cls");
            G.FloydWarshall();
            system("pause");
            system("cls");
            break;
          }
          case 'v': // Comparar Dijkstra y Bellman-Ford
            system("cls");
            G.ComparativaCM();
            system("pause");
            system("cls");
            break;
        default:
          system("cls");
          cout << endl << "Opcion no valida, intentalo de nuevo" << endl << endl;
          system("pause");
          system("cls");
          break;
      }
    }while (opcion != 'q');
  }
  cout << "Fin del programa" << endl;


	return 0;
}