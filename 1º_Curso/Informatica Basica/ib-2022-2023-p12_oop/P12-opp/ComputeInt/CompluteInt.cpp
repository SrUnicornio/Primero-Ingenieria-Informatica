/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file ComputeInt.cpp
 * @author Alvaro Perez Ramos alu0101574042@ull.edu.es
 * @date Dic 27 2022
 * @brief Desarrollo de la clase ComputeInt
 * @see https://github.com/IB-2022-2023/ib-2022-2023-p12_oop-AlvaroPerezRamos
 */

#include "ComputeInt.h"

/**
 *@brief Constructor por defecto
 *@param kNumero
 */
ComputeInt::ComputeInt() {
  kNumero = 0;
}

/**
 *@brief Funcion que calcula si un numero es perfecto
 *@param kNumero
 */
void ComputeInt::Perfecto(int kNumero) {
  int suma = 0;
  for (int i = 1; i < kNumero; i++) {
    if (kNumero % i == 0) {
      suma += i;
    }
  }
  if (suma == kNumero) {
    cout << "El numero " << kNumero << " es perfecto" << endl;
  } else {
    cout << "El numero " << kNumero << " no es perfecto" << endl;
  }
}