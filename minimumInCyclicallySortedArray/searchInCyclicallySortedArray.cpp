#include <iostream>
#include <vector>

using namespace std;

int minimumInCyclicallySorted(vector<int> &A) {
  cout << &A << endl;
  int L = 0;
  int U = A.size() - 1;
  while (L < U) {
    int M = L + (U - L) / 2;

    if (A[M] > A[U])
      L = M + 1;
    else
      U = M;
  }
  return L;
}
// in case of repititions
//
int SearchSmallestHelper(const vector<int> &A, int left, int right) {
  if (left == right)
    return left;
  int middle = left + (right - left) / 2;
  if (A[middle] > A[right])
    return SearchSmallestHelper(A, middle + 1, right);
  else if (A[middle] < A[right])
    return SearchSmallestHelper(A, left, middle);
  else {
    int leftSmallest = SearchSmallestHelper(A, left, middle);
    int rightSmallest = SearchSmallestHelper(A, middle + 1, right);
    return A[leftSmallest] > A[rightSmallest] ? rightSmallest : leftSmallest;
  }
}
int main() {

  // decreasing then increasing
  vector<int> A = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
  cout << &A << endl;
  int min = minimumInCyclicallySorted(A);
  cout << min << endl;
}
