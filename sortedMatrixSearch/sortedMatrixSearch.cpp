#include <iostream>
#include <vector>

using namespace std;

bool MatrixSearch(vector<vector<int>> &A, int x) {
  int row = 0;
  int col = A[0].size() - 1;
  while (row < (int)A.size() && col >= 0) {
    if (A[row][col] < x)
      row++;
    else if (A[row][col] > x)
      col--;
    else
      return true;
  }
  return false;
}

int main() {
  vector<vector<int>> A;
  A = {{-1, 2, 4, 4, 6},  {1, 5, 5, 9, 21},  {3, 6, 6, 9, 22},
       {3, 6, 8, 10, 24}, {6, 8, 9, 12, 25}, {8, 10, 12, 13, 40}};
  bool isPresent = MatrixSearch(A, 4);
  cout << isPresent << endl;
}
