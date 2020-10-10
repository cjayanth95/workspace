#include <iostream>
#include <limits>

using namespace std;

typedef enum { GREATER, SMALLER, EQUAL } Order;
Order Compare(double a, double b) {
  double diff = (a - b) / b;
  return diff < -numeric_limits<double>::epsilon()
             ? SMALLER
             : diff > numeric_limits<double>::epsilon() ? GREATER : EQUAL;
};

double realSquareRoot(double N) {
  double L = N > 1.0 ? 1 : N;
  double U = N > 1.0 ? N : 1;
  while (Compare(L, U) == SMALLER) {
    double M = L + 0.5 * (U - L);
    if (Compare(M * M, N) == GREATER)
      U = M;
    else if (Compare(M * M, N) == SMALLER)
      L = M;
    else
      return M;
  }
  return L;
}

int main() {
  double i = 0.16;
  double sqrt = realSquareRoot(i);
  cout << sqrt << endl;
}
