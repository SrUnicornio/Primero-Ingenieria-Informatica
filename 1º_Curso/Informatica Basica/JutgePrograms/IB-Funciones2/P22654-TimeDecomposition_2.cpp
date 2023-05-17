
#include <iostream>
using namespace std;

 void decompose(int n, int& h, int& m, int& s){
    s = n%60;
    h = n/3600;
    m = (n/60)%60;
}
int main() {

  return 0;
}