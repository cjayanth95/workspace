#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void PrintVector(const vector<int> &v) {
  for (int i : v) {
    cout << i << endl;
  }
}
void Print2DVector(const vector<vector<int>> &v) {
  for (vector<int> i : v) {
    PrintVector(i);
  }
}

vector<vector<int>> DecomposeArrayIntoSubArrays(const vector<int> &A) {
  vector<vector<int>> sortedArrays;
  typedef enum { INCREASING, DECREASING } SubArrayType;
  SubArrayType subArrayType = INCREASING;
  int start_idx = 0;
  int sizeOfA = A.size();
  for (int i = 1; i <= sizeOfA; i++) {
    if (i == sizeOfA || ((A[i - 1] > A[i]) && subArrayType == INCREASING) ||
        ((A[i - 1] < A[i]) && subArrayType == DECREASING)) {
      if (subArrayType == INCREASING) {
        sortedArrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
      } else {
        sortedArrays.emplace_back(A.crbegin() + sizeOfA - i,
                                  A.crbegin() + sizeOfA - start_idx);
      }
      start_idx = i;
      subArrayType = (subArrayType == INCREASING) ? DECREASING : INCREASING;
    }
  }

  return sortedArrays;
}

int main() {
  vector<int> v = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
  vector<vector<int>> Decomposed = DecomposeArrayIntoSubArrays(v);
  Print2DVector(Decomposed);
  return 0;
}
