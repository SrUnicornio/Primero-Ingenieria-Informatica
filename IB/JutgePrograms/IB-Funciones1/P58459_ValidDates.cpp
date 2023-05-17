
#include <iostream>
using namespace std;

 bool is_valid_date(int d, int m, int y);

int main() {
  int dia, mes, anio, fc;
  while (cin >> dia >> mes >> anio) {
    cout << "is_valid_date("<<dia<<", "<<mes<<", "<<anio<<") → ";
if(is_valid_date(dia, mes, anio)==1){cout <<"true"<<endl;}else {cout<< "false"<<endl;}
  }
  return 0;
}

bool Bisiesto(int y) {
  if (y % 100 == 0) {
    if ((y / 100) % 4 == 0)
      return true;
    return false;
  } else {
    if (y % 4 == 0)
      return true;
    return false;
  }
}

bool is_valid_date(int d, int m, int y) {
  if (d < 1 || m < 1 || y < 1800 || y > 9999 || m > 12 ||
      d > 31) {
    return false;
  }
  if (!Bisiesto(y) && m == 2 && d > 28) {
    return false;
  }
  if (m == 2 && d > 29) {
    return false;
  }
  if ((m > 7 && m % 2 != 0 && d > 30) ||
      (m <= 7 && m % 2 == 0 && d > 30)) {
    return false;
  }
  return true;
}
