#include <iostream>
#include <cmath>
using namespace std;

int main()
{

  double a{0.0};
  double b{2.0};
  const double d{0.00005};
  int i{0};
  cout << "Introduce un numero:";
  cin >> a;
  a = abs(a);

  while (d <= a)
  {
    a = a/b;
    i++;
  }
  
  cout << i << endl;
  
}