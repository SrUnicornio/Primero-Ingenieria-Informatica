
#include <iostream>
#include <math.h>
using namespace std;
int main() {
   int Num1, j=0, i=1; // J rasultado, i variable que es potenciada
  cin >> Num1;

  while (Num1 < 0) {
      cin >> Num1;
  }
if (Num1==0){cout << Num1<<endl; return 0;}
  do {
printf("%d%s", j, ",");
    j = pow(i, 3) ;
    i++;
    
  } while (i <= Num1);

  printf("%d\n", j);
  return 0;
}



