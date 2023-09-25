#include <cmath>
#include <iostream>

int convert(unsigned long int binario) {
  int decimal{0}, i{0}, resto{0};
  while (binario != 0) {
    resto = binario % 10;
    binario /= 10;
    if (resto != 0 && resto != 1) {
      return 0;
    }
    decimal += resto * std::pow(2, i);
    ++i;
  }
  return decimal;
}
int main() {
  unsigned long int binario;
  std::cout<< "Public test case \nInput \t\tOuput\n";
  while (std::cin >> binario) {
    if (convert(binario) == 0) {
      std::cout << "Wrong Input" << std::endl;
      continue;
    }
    std::cout << convert(binario) << std::endl;
  }
  return 0;
}