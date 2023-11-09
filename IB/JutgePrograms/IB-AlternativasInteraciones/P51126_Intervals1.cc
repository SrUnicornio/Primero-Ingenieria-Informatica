
#include <iostream>
using namespace std;

int main() {
  int intervalo1_a{0}, intervalo1_b{0}, intervalo2_a{0}, intervalo2_b{0};
  cin >> intervalo1_a >> intervalo1_b >> intervalo2_a >> intervalo2_b;

  int grande = min(intervalo1_b, intervalo2_b);
  int pequenio = max(intervalo1_a, intervalo2_a);

  if (pequenio > grande) {
    cout << "[]" << std::endl;
    return 0;
  }
  cout << "[" << pequenio << "," << grande << "]" << std::endl;
  return 0;
}
