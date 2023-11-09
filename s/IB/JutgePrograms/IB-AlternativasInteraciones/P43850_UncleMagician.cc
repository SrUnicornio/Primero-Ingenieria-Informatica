
#include <iostream>
using namespace std;

int main() {
    unsigned int num{0}, result{0};
    while(cin >> num) {
        result = (((((num/5)-9)/4)-6)/5);
        cout << result << endl;
    }
    return 0;
}