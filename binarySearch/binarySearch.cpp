#include <iostream>
#include <vector>

using namespace std;

int bsearch(int t, const vector<int> &A) {
  int L = 0;
  int U = A.size() - 1;
  while (L <= U) {
    int M = L + (U - L) / 2;
    if (t < A[M])
      U = M - 1;
    if (t > A[M])
      L = M + 1;
    else
      return M;
  }
  return -1;
}

int main() {
  vector<int> A = {2, 3, 4, 5, 6, 7};
  int index = bsearch(7, A);
  cout << index << endl;
  return index;
}
