#include <iostream>
using namespace std;

#ifndef COMPUTEINT_H
#define COMPUTEINT_H

class ComputeInt {
 public:
  ComputeInt();
  void Perfecto(int kNumero);
 private:
  int kNumero;
};

#endif

ComputeInt::ComputeInt() {
  kNumero = 0;
}

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
