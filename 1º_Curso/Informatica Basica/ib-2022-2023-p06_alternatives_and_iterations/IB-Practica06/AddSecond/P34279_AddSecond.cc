
#include <iostream>
using namespace std;

int main() {
  int hora, minutos, segundos;
  cin >> hora >> minutos >> segundos;

  while (hora >= 24 || minutos >= 60 || segundos >= 60) {
    if (segundos >= 60) {
		cin >> segundos;
    }
    if (minutos >= 60) {
      cin >> minutos;
    }
    if (hora >= 24) {
      cin >> hora;
    }
  }
  segundos += 1;
  if (segundos >= 60) {
    minutos = minutos + (segundos / 60);
    segundos = segundos % 60;
  }
  if (minutos >= 60) {
    hora = hora + (minutos / 60);
    minutos = minutos % 60;
  }
  if (hora >= 24) {
    hora = hora % 24;
  }
  printf("%02d:%02d:%02d", hora, minutos, segundos);
  return 0;
}
