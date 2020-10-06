#include <deque>
#include <math.h>
#include <vector>
using namespace std;
bool HasDuplicates(vector<vector<int>> &partial_assignment, int start_row,
                   int end_row, int start_col, int end_col) {
  deque<bool> is_present(partial_assignment.size() + 1, false);
  for (int i = start_row; i < end_row; i++) {
    for (int j = start_col; j < end_col; j++) {
      if ((partial_assignment[i][j] != 0) &&
          is_present[partial_assignment[i][j]])
        return true;
      if (partial_assignment[i][j] != 0)
        is_present[partial_assignment[i][j]] = true;
    }
  }
  return false;
}

bool isValidSudoku(vector<vector<int>> &partial_assignment) {
  for (int i = 0; i < (int)partial_assignment.size(); ++i) {
    if (HasDuplicates(partial_assignment, i, i + 1, 0,
                      partial_assignment.size()))
      return false;
  }
  for (int j = 0; j < (int)partial_assignment.size(); ++j) {
    if (HasDuplicates(partial_assignment, 0, partial_assignment.size(), j,
                      j + 1))
      return false;
  }
  int regionSize = sqrt(partial_assignment.size());
  for (int I = 0; I < regionSize; I++) {
    for (int J = 0; J < regionSize; J++) {
      if (HasDuplicates(partial_assignment, I * regionSize,
                        (I + 1) * regionSize, J * regionSize,
                        (J + 1) * regionSize))
        return false;
    }
  }
  return true;
}
int main() {
  vector<vector<char>> &partial_assignment = [
    [ "5", "3", ".", ".", "7", ".", ".", ".", "." ],
    [ "6", ".", ".", "1", "9", "5", ".", ".", "." ],
    [ ".", "9", "8", ".", ".", ".", ".", "6", "." ],
    [ "8", ".", ".", ".", "6", ".", ".", ".", "3" ],
    [ "4", ".", ".", "8", ".", "3", ".", ".", "1" ],
    [ "7", ".", ".", ".", "2", ".", ".", ".", "6" ],
    [ ".", "6", ".", ".", ".", ".", "2", "8", "." ],
    [ ".", ".", ".", "4", "1", "9", ".", ".", "5" ],
    [ ".", ".", ".", ".", "8", ".", ".", "7", "9" ]
  ];
}
