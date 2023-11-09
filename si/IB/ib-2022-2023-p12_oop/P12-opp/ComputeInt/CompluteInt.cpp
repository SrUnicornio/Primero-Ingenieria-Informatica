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
