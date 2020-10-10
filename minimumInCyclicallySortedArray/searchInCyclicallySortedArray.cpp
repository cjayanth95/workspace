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
int main() {

  // decreasing then increasing
  vector<int> A = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
  cout << &A << endl;
  int min = minimumInCyclicallySorted(A);
  cout<<min<<endl;
}
