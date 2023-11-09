#include <iostream>
using namespace std;

void inverpalabrao() {
  string palabra;  
  if (cin >> palabra) {
        inverpalabrao();
        cout << palabra << endl;
    }
}


int main() {
  inverpalabrao();

}
