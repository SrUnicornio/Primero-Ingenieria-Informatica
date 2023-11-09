
#include <iostream>
using namespace std;

void count_and_add(int& num, int& sum){
  sum=0;
  num=0;
  int x;
  while (cin >> x){
    ++num;
    sum += x;
  }
}

int main() {
  int knumero{0}, ksuma{0};
    count_and_add(knumero, ksuma);
  cout << knumero <<" "<< ksuma << endl;
}