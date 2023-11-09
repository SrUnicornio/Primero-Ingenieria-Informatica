
#include <iostream>
using namespace std;
int main() {

  int Hora, Minutos, Second;

  cin >> Hora >> Minutos >> Second;

  /*Bucle que dictamina que hasta que la hora dada sea unferior a 24:60:60 o
   contenga dichos caracteres se repita de forma constante.*/
  while (Hora >= 24 or Minutos >= 60 or Second >= 60) {
    if (Second >= 60) {
    }
    if (Minutos >= 60) {
      cin >> Minutos;
    }
    if (Hora >= 24) {

      cin >> Hora;
    }
  }

  Second = Second + 1; // Aniade un segundo a la hora dada

  /** Si al añadir un X segundos este da 60 suma un minuto y lo mismo con los mitutos para las horas y las horas a los segundos
*/
  if (Second >= 60) {
    Minutos = Minutos + (Second / 60);
    Second = Second % 60;
  }
  if (Minutos >= 60) {
    Hora = Hora + (Minutos / 60);
    Minutos = Minutos % 60;
  }
  if (Hora >= 24) {

    Hora = Hora % 24;
  }

  char s[25];
  sprintf(s, "%02d:%02d:%02d", Hora, Minutos, Second);
  cout << s << endl;
  return 0;
}