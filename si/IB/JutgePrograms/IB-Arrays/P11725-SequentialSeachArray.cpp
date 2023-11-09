
#include <iostream>
#include <vector>
using namespace std;

bool exists(int x, const vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    if (v[i] == x) {
      return true;
    }
  }
  return false;
}