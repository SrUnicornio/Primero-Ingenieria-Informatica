
#include <iostream>
using namespace std;
int main() {
  int Second=0, Minutos=0, Hora=0;
  cin >> Second;
  if (Second >=60) {
    Minutos = Second / 60;
    Second = Second % 60;
  }
  if (Minutos >=60) {
    Hora = Minutos / 60;
    Minutos = Minutos % 60;
  }
  
  cout << Hora << " " << Minutos << " " << Second << endl;
  return 0;
}
