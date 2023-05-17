
#include<iostream>
using namespace std;
 
long int mcd(long int n1, long int n2) {
    if(n1 < n2) return mcd(n2,n1);
    if(n2 == 0) return n1;
    return mcd(n2, n1 % n2);
}
 
long int mcm(long int n1, long int n2) {
    long int producto = (n1*n2)/mcd(n1,n2);
    return producto;
}

int main() {
    long int numero1;
    long int numero2;
    while (cin >> numero2) {
        long int producto = 1;
        if (numero2 == 0);
        else {
            int i = 0;
            while (i < numero2) {
                cin >> numero1;
                producto = mcm(producto, numero1);
                i++;
            }
            cout << producto << endl;
        }
    }
}