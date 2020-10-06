#include <math.h>
#include <vector>
using namespace std;

const int kEmptyEntry = 0;

bool validToAdd(vector<vector<int>> &partial_assignment, int i, int j,
                int val) {
  for (int k = 0; k < (int)partial_assignment.size(); k++) {
    if (val == partial_assignment[i][k])
      return false;
  }

  for (int l = 0; l < (int)partial_assignment.size(); l++) {
    if (val == partial_assignment[l][j])
      return false;
  }
  int regionSize = sqrt(partial_assignment.size());
  int I = i / regionSize;
  int J = j / regionSize;
  for (int a = 0; a < regionSize; a++) {
    for (int b = 0; b < regionSize; b++) {
      if (partial_assignment[I * regionSize + a][J * regionSize + b] == val)
        return false;
    }
  }
  return true;
}
bool solvePartialSudoku(vector<vector<int>> *partial_assignment, int i, int j) {
  if (i == (int)partial_assignment->size()) {

    i = 0;
    if (++j == (int)partial_assignment[i].size())
      return true;
  }
  if ((*partial_assignment)[i][j] != kEmptyEntry)
    return solvePartialSudoku(partial_assignment, i + 1, j);
  for (int val = 1; val < (int)partial_assignment->size(); val++) {
    if (validToAdd(*partial_assignment, i, j, val)) {

      (*partial_assignment)[i][j] = val;
      if (solvePartialSudoku(partial_assignment, i + 1, j))
        return true;
    }
  }
  (*partial_assignment)[i][j] = 0;
  return false;
}
bool solveSudoku(vector<vector<int>> *partial_assignment) {
  return solvePartialSudoku(partial_assignment, 0, 0);
}
int main() {
  vector<char> row1 = {"5", "3", ".", ".", "7", ".", ".", ".", "."};
   {"6", ".", ".", "1", "9", "5", ".", ".", "."},
   {".", "9", "8", ".", ".", ".", ".", "6", "."},
   {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
   {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
   {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
   {".", "6", ".", ".", ".", ".", "2", "8", "."},
   {".", ".", ".", "4", "1", "9", ".", ".", "5"},
   {".", ".", ".", ".", "8", ".", ".", "7", "9"}]
}
