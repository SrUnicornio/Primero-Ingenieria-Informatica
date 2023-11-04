#include <iostream>
using namespace std;

int main() {
  unsigned int numero, n;
  
  while (cin >> numero) {
    if (numero<10){cout << "The product of the digits of " << numero << " is " << numero<< "."<<endl;}
    while (numero >= 10) {
		int producto{1};
		n = numero;
		while (numero != 0){
			producto *=(numero % 10);
			numero /= 10;
		}
		cout << "The product of the digits of " << n << " is " << producto << "."
           << endl;
      numero = producto;
    }
    cout << "----------"<<endl;
    }
  return 0;
}
