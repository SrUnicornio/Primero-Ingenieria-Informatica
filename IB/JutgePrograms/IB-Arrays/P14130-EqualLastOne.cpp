
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int knumero{0};
  cin >> knumero;
  vector<int>  v(knumero);
  int j{0};
  for(int i = 0; i < knumero; ++i){
    cin >> v[i];
  }
  for (int k = knumero - 2; k >= 0; --k) {
        if (v[knumero-1] == v[k]) j++;
    }
    cout << j << endl;
  return 0;
}