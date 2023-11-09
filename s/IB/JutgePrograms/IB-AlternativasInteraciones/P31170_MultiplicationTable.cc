
#include <iostream>
using namespace std;
int main() {
  int Tabla, i = 1;
  cin >> Tabla;
  while (Tabla < 0) {
    cin >> Tabla;
  }

  do {
   printf("%d%s%d%s%d\n",Tabla, "*",i, " = ", Tabla*i);
    i++;
  } while (i <= 10);
  return 0;
}