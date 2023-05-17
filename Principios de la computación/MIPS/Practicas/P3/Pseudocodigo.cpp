#include <iostream>

int main() {
  // Matriz de 4x4
  int matriz[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  std::cout << "Matriz:";
  // Imprime la matriz
  for (int i = 0; i < 4; i++) {
    std::cout << std::endl;
    for (int j = 0; j < 4; j++) {
      std::cout << matriz[i][j] << " ";
    }
  }

  // pide al usuario un numero, si numero es mayor a 16, vuelve a pedir
  int numero;
  std::cout << "\nIngrese un numero: ";
  std::cin >> numero;
  while (numero > 4) {
    std::cout << "Vuelva a ingresar un numero: ";
    std::cin >> numero;
  }
  int suma = 0;
  // Suma la columna del numero ingresado
  for (int i = 0; i < 4; i++) {
    suma += matriz[i][numero - 1];
  }
  std::cout << "La suma de la columna es: " << suma << std::endl;
  return 0;
}