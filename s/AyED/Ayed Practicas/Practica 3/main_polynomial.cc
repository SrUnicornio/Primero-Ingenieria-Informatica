// AUTOR: 
// FECHA: 13/03/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_polynomial.cc -o main_polynomial
// EJECUCIÓN: ./main_polynomial < data_polynomial.txt

#include <iostream>

#include "polynomial.h"

using namespace std;

int main()
{
  Polynomial p1, p2, p3;
  
  cin >> p1 >> p2 >> p3;
  cout << "p1= " << p1;
  cout << "p2= " << p2;
  cout << "p3= " << p3;
  cout << endl;

   // Fase II
  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);
  cout << "sp1= " << sp1;
  cout << "sp2= " << sp2;
  cout << "sp3= " << sp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << "p1(" << x1 << ")= " << p1.Eval(x1) << endl;
  cout << "p1(" << x2 << ")= " << p1.Eval(x2) << endl;
  cout << "p1(" << x3 << ")= " << p1.Eval(x3) << endl;
  cout << "p2(" << x1 << ")= " << p2.Eval(x1) << endl;
  cout << "p2(" << x2 << ")= " << p2.Eval(x2) << endl;
  cout << "p2(" << x3 << ")= " << p2.Eval(x3) << endl;
  cout << "p3(" << x1 << ")= " << p3.Eval(x1) << endl;
  cout << "p3(" << x2 << ")= " << p3.Eval(x2) << endl;
  cout << "p3(" << x3 << ")= " << p3.Eval(x3) << endl;
  cout << endl;

  cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << endl;
  cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << endl;
  cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << endl;
  cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << endl;
  cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << endl;
  cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << endl;
  cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << endl;
  cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << endl;
  cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << endl;
  cout << endl;

  // Fase IV
  cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

  // Modificaciones
  // Operaciones con polinomios
  std::cout << "Operaciones con polinomios" << std::endl;
  cout << "p1 + p2 = " << p1 + p2 << endl;
  cout << "p1 - p3 = " << p1 - p2 << endl;
  cout << "p1 * p3 = " << p1 * p3 << endl;
  cout << "p1 / p3 = " << p1 / p3 << endl;

  // Saber que numero hay en un indice
  std::cout << "Saber que numero hay en un indice del vector" << std::endl;
  int n = 2;
  cout << "Para indice = " << n << " el valor del polinomio sp1 " << sp1 << "es: ";
  sp1.Modificacion(n);

  // Muestra los coeficientes de un polinomio a partir de un indice dado
  int m = 1;
  std::cout << "\nMuestra los coeficientes de un polinomio a partir de un indice dado" << std::endl;
  cout << "A partir del indice dado " << m << " del polinomio " << sp2 << "el resultado restante es: ";
  sp2.MostrarValores(m);

  // Muestra los grados pares o impares del polinomio dependiendo del indice dado
  std::cout << "\nMuestra los grados pares o impares del polinomio dependiendo del indice dado" << std::endl;
  cout << "A partir del indice = " << n << " para el polinomio sp1 " << sp1 << "los grados pares son: ";
  sp1.MostrarValores2(n);
  cout << "A partir del indice = " << m << " para el polinomio sp1 " << sp1 << "los grados impares son: ";
  sp1.MostrarValores2(m);

  // Resultado de la suma de los coeficientes de un polinomio a partir de un indice dado
  double X_value = 3.01;
  std::cout << "\nResultado de la suma de los coeficientes de un polinomio a partir de un indice dado" << std::endl;
  cout << "Para indice = " << n << " para el polinomio sp1 " << sp1 << "el resultado de la suma de los coeficientes es: " << sp1.Eval2(n, X_value) << endl;

  // Resultado de la suma de los coeficientes pares o impares de un polinomio a partir de un indice dado
  std::cout << "Resultado de la suma de los coeficientes pares o impares de un polinomio a partir de un indice dado" << std::endl;
  cout << "\nPara indice = " << n << " para el polinomio sp1 " << sp1 << "el resultado de la suma de los coeficientes pares es: " << sp1.Eval3(n, X_value) << endl;
  cout << "Para indice = " << m << " para el polinomio sp1 " << sp1 << "el resultado de la suma de los coeficientes impares es: " << sp1.Eval3(m, X_value) << endl;
  
  // Imprime el polinomio y sus indices
  std::cout << "\nImprime el polinomio y sus indices" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "Los indices son: ";
  sp1.MostrarIndices();

  // Comparar polinomios
  cout << "\nPolinomio mayor a otro: " << endl;
  cout << "sp1 > sp2 ? " << (sp1.IsGreater(sp2) ? "true" : "false") << endl;
  cout << "sp2 > sp1 ? " << (sp2.IsGreater(sp1) ? "true" : "false") << endl;
  cout << "sp1 > sp3 ? " << (sp1.IsGreater(sp3) ? "true" : "false") << endl;
  cout << "sp3 > sp1 ? " << (sp3.IsGreater(sp1) ? "true" : "false") << endl;
  cout << "sp2 > sp3 ? " << (sp2.IsGreater(sp3) ? "true" : "false") << endl;
  cout << "sp3 > sp2 ? " << (sp3.IsGreater(sp2) ? "true" : "false") << endl;
  cout << endl;

  cout << "Polinomio menor a otro: " << endl;
  cout << "sp1 < sp2 ? " << (sp1.IsLess(sp2) ? "true" : "false") << endl;
  cout << "sp2 < sp1 ? " << (sp2.IsLess(sp1) ? "true" : "false") << endl;
  cout << "sp1 < sp3 ? " << (sp1.IsLess(sp3) ? "true" : "false") << endl; 
  cout << "sp3 < sp1 ? " << (sp3.IsLess(sp1) ? "true" : "false") << endl;
  cout << "sp2 < sp3 ? " << (sp2.IsLess(sp3) ? "true" : "false") << endl;
  cout << "sp3 < sp2 ? " << (sp3.IsLess(sp2) ? "true" : "false") << endl;
  cout << endl;

  // Mostrar el valor mayor de un vector y su indice
  std::cout << "Mostrar el valor mayor de un vector y su indice" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "el valor mayor es: "; sp1.Mayor();
  
  // Mostrar el valor menor de un vector y su indice
  std::cout << "\nMostrar el valor menor de un vector y su indice" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "el valor menor es: "; sp1.Menor();

  // Dado el Polinomio, suma los indices pares y resta los impares
  std::cout << "\nDado el Polinomio, suma los indices pares y resta los impares" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "el resultado es: "; sp1.Eval4(X_value);

  // Imprimir el polinomio en orden inverso
  std::cout << "Imprimir el polinomio en orden inverso" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "el polinomio en orden inverso es: "; sp1.Inverse();

  // Mayor indice entre dos polinomios
  std::cout << "\nMayor indice entre dos polinomios" << std::endl;
  cout << "Para el polinomio sp1 " << sp1 << "y el polinomio sp2 " << sp2 << "el mayor indice es: "; sp1.MaxVal(sp2);
  return 0;
}
