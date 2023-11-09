#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<double> GenerateVector(const int size, const double lower,
                              const double upper) {
  double num;
  vector<double> V(size);
  for (int i = 1; i <= size; ++i) {
    num = lower + (double)(rand()) / ((double)(RAND_MAX / (upper - lower)));
    V.push_back(num);
  }
   return V;
}

int main() {
  int size;
  double min, max;
  cin >> size >> min >> max;
  while(min > max){cin >> max;}
  while (min == 0){cin >> min;}
  vector<double> my_vector = GenerateVector(size, min, max);
  for(int i = 0; i < size; ++i){
  my_vector.erase(my_vector.begin());}
  for (const auto& value : my_vector) {
   cout << fixed << setprecision(3) << "Component: " << value << endl;
   }
  return 0;
}
