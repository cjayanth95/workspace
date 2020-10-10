#include <iostream>

using namespace std;

int integerSquareRoot(int k) {
  int L = 0;
  int U = k;
  while (L <= U) {
    int M = L + (U - L) / 2;
    if (M * M > k)
      U = M - 1;
    else if (M * M <= k)
      L = M + 1;
  }
  return L - 1;
}

int main() {
  int g = integerSquareRoot(99);
  cout << g << endl;
}
