
#include <iostream>
#include <cmath>
using namespace std;

int number_of_digits(int a) {
	int i{1}; 
  if (a!=0){
	i = (log10(a))+1;}
	return i;
}

int main() {
	int numero;
	while(cin >> numero){
	cout <<"number_of_digits("<<numero<<") → "<< number_of_digits(numero) << endl;
}
}