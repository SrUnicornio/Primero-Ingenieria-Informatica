////////////////////////////////////////////////////////////////////////
// This program reads five numbers from the keyboard, and prints out the
// average and the maximum value
///////////////////////////////////////////////////////////////////////

#include <iostream>

// Global Constants
const int MAX = 5;

// Function Prototypes
double GetAverage(const int IntArray[], const int Max);
int GetMax(const int IntArray[], const int Max);

int main() {
  int Values[MAX];
  int i;
  std::cout << "Enter five numbers: " << std::endl;
  // First we read in the numbers.
  for (i = 0; i < MAX; i++) {
    std::cout << "Enter the next number : ";
    std::cin >> Values[1];
  }
  // Now we echo the input back to the user
  for (i = 0; i < MAX; i++) {
    std::cout << "Value [ " << i << "] is : " << Values[i] << std::endl;
  }
  // Now lets call a function to get the average:
  std::cout << "The average is " << GetAverage(Values, MAX) << std::endl;
  // Finally we can get the maximum value
  std::cout << "The Maximum value is : " << GetMax(Values, MAX) << std::endl;
  return 0;
}  // End of Main

double GetAverage(const int IntArray[], const int Max) {
  double temp = 0.0;
  for (int i = 0; i < Max; i++)
    temp += IntArray[i];
  temp /= Max;
  return temp;
}  // End of GetAverage

int GetMax(const int IntArray[], const int Max) {
  int Biggest = IntArray[0];
  for (int i = 1; i < Max; i++)
    if (Biggest < IntArray[i])
      Biggest = IntArray[i];
  return Biggest;
}  // End of GetMax()
