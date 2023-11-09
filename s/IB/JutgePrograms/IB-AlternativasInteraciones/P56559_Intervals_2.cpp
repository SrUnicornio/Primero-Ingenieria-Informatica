
#include <iostream>
using namespace std;

int main() {
  int intervalo_a1{0}, intervalo_b1{0}, intervalo_a2{0}, intervalo_b2{0};
  cin >> intervalo_a1 >> intervalo_b1 >> intervalo_a2 >> intervalo_b2;

   if (intervalo_a1 == intervalo_a2 && intervalo_b1 == intervalo_b2) {
    cout << '=' << endl;
    return 0;
  }
  if (intervalo_a1 >= intervalo_a2 && intervalo_b1 <= intervalo_b2) {
    cout << '1' << endl;
    return 0;
  }
  if ((intervalo_a1 < intervalo_a2 && intervalo_b1 >= intervalo_b2) ||
      (intervalo_a1 <= intervalo_a2 && intervalo_b1 > intervalo_b2)) {
    cout << '2' << endl;
    return 0;
  }
  cout << '?' << endl;
  return 0;
}
