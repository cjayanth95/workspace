#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool allInputsNegative(const vector<int> &A) {
  return std::all_of(A.begin(), A.end(), [](int i) { return i < 0; });
}
int main() {
  //  vector<int> A{904, 40, 523, 12, -335, -385, -124, 481, -31};
  vector<int> A{-1, -1};
  // bool areAllInputsNegative = allInputsNegative(A);
  // if (areAllInputsNegative)
  //  return *max_element(A.begin(), A.end());
  int max_sum = 0, sum = 0, min_sum = 0;
  bool areAllInputsNegative = true;
  for (int i : A) {
    if (i > 0)
      areAllInputsNegative = false;
    sum += i;
    if (min_sum > sum)
      min_sum = sum;
    if (max_sum < sum - min_sum)
      max_sum = sum - min_sum;
  }
  if (areAllInputsNegative)
    return *max_element(A.begin(), A.end());

  cout << max_sum << endl;
  return 1;
}
