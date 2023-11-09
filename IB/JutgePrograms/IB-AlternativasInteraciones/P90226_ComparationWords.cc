#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string palabra1, palabra2;

    cin >> palabra1 >> palabra2;

if ( palabra1 < palabra2 ) {
        cout << palabra1 << " < " << palabra2 << endl;
        return 0;
    }
    else if ( palabra1 > palabra2 ) {
        cout << palabra1 << " > " << palabra2 << endl;
        return 0;
    }
    else if ( palabra1 == palabra2 ) {
        std::cout << palabra1 << " = " << palabra2 << std::endl;
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}