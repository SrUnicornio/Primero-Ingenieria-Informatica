#include <iostream>
using namespace std;

int main() {
	long int base{0}, exponente{0};
	while (cin >> base >> exponente){
	if (exponente == 1){
					cout << "1"<<endl;
				 	continue;}
		long int potenciado{1};
		for(int i = 0; i <= exponente; i++){
			potenciado *= base;
		}
	cout << potenciado << endl;
	}
	return 0;
}
