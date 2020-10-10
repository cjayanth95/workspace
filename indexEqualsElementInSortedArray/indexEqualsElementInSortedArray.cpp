#include <iostream>
#include <vector>

using namespace std;

int findIndex(vector<int> &A) {
  int L = 0;
  int U = A.size() - 1;
  while (L <= U) {
    int M = L + (U - L) / 2;
    if (A[M] - M > 0) {
      U = M - 1;
    } else if (A[M] - M < 0) {
      L = M + 1;
    } else
      return M;
  }
  return -1;
}
int main() {
  vector<int> A = {-2, 0, 2, 3, 6, 7, 9};
  int idx = findIndex(A);
  cout << idx << endl;
}
