
#include <iostream>
using namespace std;

 bool is_leap_year(int year);

int main() {
  int anio;
  while (cin >> anio) {
    cout << "is_leap_year("<<anio<<") → ";
if(is_leap_year(anio)==1){cout <<"true"<<endl;}else {cout<< "false"<<endl;}
  }
  return 0;
}

bool is_leap_year(int year) {
  if (year % 100 == 0) {
    if ((year / 100) % 4 == 0)
      return true;
    return false;
  } else {
    if (year % 4 == 0)
      return true;
    return false;
  }
}