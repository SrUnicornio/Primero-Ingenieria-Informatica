
#include <iostream>
using namespace std;
int main()
{
   int anio;
   cin >> anio;

   if(anio%4 == 0 and anio%100 != 0 or anio%400 == 0){               
      cout << "YES" << endl;}
   else{
      cout << "NO" << endl;}
   return 0; 
}