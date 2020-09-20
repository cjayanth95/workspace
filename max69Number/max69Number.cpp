#include <cmath>
#include <iostream>
using namespace std;
int reverseNumber(int n) {
  int result = 0;
  while (n) {
    result *= 10;
    result += n % 10;
    n /= 10;
  }
  return result;
}
int findFirstOccurenceOfSix(int n) {
  int output = 0;
  bool sixFound = false;
  while (n) {
    if (n % 10 == 6) {

      sixFound = true;
      break;
    }
    output++;
    n /= 10;
  }
  return output;
}
int countDigits(int n) { return floor(log10(n)) + 1; }
int main() {
  int n = 96;
  int reversedNumber = reverseNumber(n);
  int firstSix = findFirstOccurenceOfSix(reversedNumber);
  int numDigits = countDigits(n);
  int output = n;
  if (firstSix <= numDigits)
    output = n + pow(10, numDigits - firstSix - 1  ) * 3;
  cout << output << endl;
  return output;
}
