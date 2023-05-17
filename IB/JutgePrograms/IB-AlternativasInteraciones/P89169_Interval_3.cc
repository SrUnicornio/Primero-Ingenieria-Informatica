
#include <iostream>
using namespace std;

char ComprobadorIntervalo(const int &ia1, const int &ib1, const int &ia2,
                          const int &ib2) {
  if (ia1 == ia2 && ib1 == ib2) {
    return '=';
  }
  if (ia1 >= ia2 && ib1 <= ib2) {
    return '1';
  }
  if ((ia1 < ia2 && ib1 >= ib2) || (ia1 <= ia2 && ib1 > ib2)) {
    return '2';
  }
  return '?';
}

void DentroIntervalo(const int &ia1, const int &ib1, const int &ia2,
                     const int &ib2) {
  if (max(ia1, ia2) > min(ib1, ib2)) {
    cout << "[]";
    return;
  }
  cout << "[" << max(ia1, ia2) << "," << min(ib1, ib2) << "]";
}

int main() {
  int intervalo_a1{0}, intervalo_b1{0}, intervalo_a2{0}, intervalo_b2{0};
  cin >> intervalo_a1 >> intervalo_b1 >> intervalo_a2 >> intervalo_b2;
  cout << ComprobadorIntervalo(intervalo_a1, intervalo_b1, intervalo_a2,
                               intervalo_b2)
       << " , ";
        DentroIntervalo(intervalo_a1, intervalo_b1, intervalo_a2,
                          intervalo_b2);
      cout << endl;
}