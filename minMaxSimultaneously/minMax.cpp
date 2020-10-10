#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct MinMax {
  int min;
  int max;
};

MinMax FindMinMax(vector<int> &A) {
  if (A.size() <= 1)
    return {A.front(), A.front()};
  pair<int, int> global_min_max = minmax(A[0], A[1]);

  for (int i = 2; i < (int)A.size() - 1; i += 2) {
    pair<int, int> local_min_max = minmax(A[i], A[i + 1]);
    global_min_max = {min(global_min_max.first, local_min_max.first),
                      max(global_min_max.second, local_min_max.second)};
  }
  if (A.size() % 2)
    global_min_max = {min(global_min_max.first, A.back()),
                      max(global_min_max.second, A.back())};
  return {global_min_max.first, global_min_max.second};
};

int main() {
  vector<int> A = {3, 2, 5, 1, 2, 4};
  MinMax minmax = FindMinMax(A);
  cout << minmax.min << endl;
  cout << minmax.max << endl;
}
