#include <iostream>
using namespace std;
int factorial(int n) {
  cout << "hit here" << endl;
  int result = 1;
  while (n) {
    cout << "hit here as well" << endl;
    result *= n;
    n--;
    cout << result << endl;
  }
  return result;
}
int main() {
  int n = 10;
  int result = factorial(n);
  cout << result << endl;
  return result;
}
