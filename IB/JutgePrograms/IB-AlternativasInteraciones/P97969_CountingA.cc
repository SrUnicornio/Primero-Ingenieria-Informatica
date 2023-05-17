
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int contador(string frase, char letra_a){
 return count(frase.begin(), frase.end(), letra_a);
  }
int main(void){
string input;

  getline(cin, input);

cout << contador(input, 'a') <<endl;

  return 0;
}
