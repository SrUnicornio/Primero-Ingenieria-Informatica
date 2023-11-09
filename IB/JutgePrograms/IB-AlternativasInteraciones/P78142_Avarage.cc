
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double numero{0}, sumatoria{0};
  int i{0};
  while (cin >> numero) {
    sumatoria += numero;
    i++;
  }
  cout << fixed << setprecision(2) << sumatoria / i << endl;
}