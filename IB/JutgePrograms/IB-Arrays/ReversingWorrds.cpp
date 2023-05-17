
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int i{0};
  string palabra = " ";
    while(cin >> palabra){
    reverse(palabra.begin(), palabra.end());
    cout << palabra << endl;}
  
  return 0;
}