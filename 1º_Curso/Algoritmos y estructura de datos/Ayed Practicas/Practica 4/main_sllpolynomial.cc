// AUTOR: Álvaro Pérez Ramos
// FECHA: 30/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_sllpolynomial.cc -o main_sllpolynomial
// EJECUCIÓN: ./main_sllpolynomial < data_sllpolynomial.txt

#include <iostream>

#include "sllpolynomial.h"

using namespace std;

int main()
{
  vector_t<double> v1, v2, v3;  // Definición de vectores
  cin >> v1 >> v2 >> v3;        // Lectura de vectores
  cout << "v1= " << v1;         // Escritura de vectores
  cout << "v2= " << v2;         // Escritura de vectores
  cout << "v3= " << v3;         // Escritura de vectores
  cout << endl;

  // Fase II
  SllPolynomial sllp1(v1), sllp2(v2), sllp3(v3); // Definición de polinomios
  cout << "sllp1= " << sllp1;    // Escritura de polinomios
  cout << "sllp2= " << sllp2;    // Escritura de polinomios
  cout << "sllp3= " << sllp3;    // Escritura de polinomios
  cout << endl;

  // Fase III
  double x1, x2, x3;           // Definición de variables 
  cin >> x1 >> x2 >> x3;       // Lectura de variables
  cout << "sllp1(" << x1 << ")= " << sllp1.Eval(x1) << endl; // Calculo del sllp1 en x1
  cout << "sllp1(" << x2 << ")= " << sllp1.Eval(x2) << endl; // Calculo del sllp1 en x2
  cout << "sllp1(" << x3 << ")= " << sllp1.Eval(x3) << endl; // Calculo del sllp1 en x3
  cout << "sllp2(" << x1 << ")= " << sllp2.Eval(x1) << endl; // Calculo del sllp2 en x1
  cout << "sllp2(" << x2 << ")= " << sllp2.Eval(x2) << endl; // Calculo del sllp2 en x2
  cout << "sllp2(" << x3 << ")= " << sllp2.Eval(x3) << endl; // Calculo del sllp2 en x3
  cout << "sllp3(" << x1 << ")= " << sllp3.Eval(x1) << endl; // Calculo del sllp3 en x1
  cout << "sllp3(" << x2 << ")= " << sllp3.Eval(x2) << endl; // Calculo del sllp3 en x2
  cout << "sllp3(" << x3 << ")= " << sllp3.Eval(x3) << endl; // Calculo del sllp3 en x3
  cout << endl;

  cout << "sllp1 == sllp1? " << (sllp1.IsEqual(sllp1) ? "true" : "false") // Comprobación de igualdad
       << endl;
  cout << "sllp2 == sllp2? " << (sllp2.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp3? " << (sllp3.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp2? " << (sllp1.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp1? " << (sllp2.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp3? " << (sllp1.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp1? " << (sllp3.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp3? " << (sllp2.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp2? " << (sllp3.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << endl;

  // Fase IV
  SllPolynomial sllpsum12, sllpsum23; //Suma de sllp1 y sllp2, sllp2 y sllp3
  sllp1.Sum(sllp2, sllpsum12);
  cout << "sllp1 + sllp2= " << sllpsum12;
  sllp2.Sum(sllp3, sllpsum23);
  cout << "sllp2 + sllp3= " << sllpsum23;
  cout << endl;

  // Modificación
  // Imprimir los monomios de grado impar
  cout<<endl;
  cout<<"Modificacion"<<endl;
  cout<<endl;

  SllPolynomial sllimpar;
  sllp1.Impar(sllimpar);
  cout << sllimpar;

  SllPolynomial sllpsub12, sllpsub23; //Resta de sllp1 y sllp2, sllp2 y sllp3
  sllp1.Sub(sllp2, sllpsub12);
  cout << "sllp1 - sllp2= " << sllpsub12;
  sllp2.Sub(sllp3, sllpsub23);
  cout << "sllp2 - sllp3= " << sllpsub23;
  cout << endl;

  SllPolynomial sllremove;
  sllp1.RemoveFirstLast(sllremove);
  cout << "sllp1 sin el primer y ultimo monomio= " << sllremove;

  cout << "Evalueacion en los indices paras con sllp1(" << x1 << ")= " << sllp1.eval_par(x1) << endl;

  // Ordena el polinomio de mayor a menor segun su coeficiente
  SllPolynomial sllp1_ordenado;
  sllp1.ordenar(sllp1_ordenado);
  cout << "sllp1 ordenado= " << sllp1_ordenado;

  return 0;
}
