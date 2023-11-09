#include "Fecha.h"
using namespace std;

int main() {
    Fecha fecha1(1, 2, 2020);
    Fecha fecha2(3, 4, 2121);
    Fecha resultado;
    cout << "Fecha 1: " << fecha1 << endl;
    cout << "Fecha 2: " << fecha2 << endl;
    cout << "Fecha 1 es bisiesto: ";
    if(fecha1.es_bisiesto() == true){cout << "yes";} else {cout << "no";} 
    cout<< endl;
    cout << "Fecha 2 es bisiesto: ";
    if(fecha2.es_bisiesto() == true){cout << "yes";} else {cout << "no";}  
    cout << endl;
    cout << "Fecha 1 es valida: ";
    if(fecha1.es_valida() == true){cout << "yes";} else {cout << "no";}
    cout << endl;
    cout << "Fecha 2 es valida: ";
    if(fecha2.es_valida() == true){cout << "yes";} else {cout << "no";}
    cout << endl;
  return 0;
}
