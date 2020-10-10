#include <iostream>
#include <vector>

using namespace std;

int firstOccurence(int t, vector<int> &A) {
  int target = -1;
  int L = 0;
  int U = A.size() - 1;
  while (L <= U) {
    int M = L + (U - L) / 2;
    if (A[M] < t)
      L = M + 1;
    else if (A[M] > t)
      U = M - 1;
    else {
      target = M;
      U = M - 1;
    }
  }
  return target;
}

int main() {
  vector<int> A = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
  int idx = firstOccurence(108, A);
  cout << idx << endl;
}
