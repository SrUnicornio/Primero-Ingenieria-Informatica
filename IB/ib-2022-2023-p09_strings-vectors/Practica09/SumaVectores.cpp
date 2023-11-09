#include <iostream>
#include <vector>
using namespace std;

int ReduceSum(const vector<int> V) {
  int size = V.size();
  double suma{0};
  for (int i = size ; i >= 0; --i) {
    suma += V[i];
  }
  return suma;
}

int main() {
  int size{0}, i;
  cin >> size;
  vector<int> V(size);
  for (i = 0; i < size; ++i) {
    cin >> V[i];
  }
  cout << ReduceSum(V) << endl;
}