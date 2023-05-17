
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned int num1{0}, num2{0};
    cin >> num1 >> num2;
    cout << "The gcd of " << num1 << " and " << num2 << " is " << __gcd(num1,num2) << "." << endl;
    return 0;
}