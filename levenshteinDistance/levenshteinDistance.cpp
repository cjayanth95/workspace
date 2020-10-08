#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int computeDistanceBetweenPrefixes(
    string &A, int a_idx, string &B, int b_idx,
    vector<vector<int>> *distance_between_prefixes_ptr) {
  vector<vector<int>> &distance_between_prefixes =
      *distance_between_prefixes_ptr;
  if (a_idx < 0)
    return b_idx;
  if (b_idx < 0)
    return a_idx;
  if (distance_between_prefixes[a_idx][b_idx] == -1) {

    if (A[a_idx] == B[b_idx])
      return computeDistanceBetweenPrefixes(A, a_idx - 1, B, b_idx - 1,
                                            distance_between_prefixes_ptr);
    int substituteLast = computeDistanceBetweenPrefixes(
        A, a_idx - 1, B, b_idx - 1, distance_between_prefixes_ptr);
    int addLast = computeDistanceBetweenPrefixes(A, a_idx - 1, B, b_idx,
                                                 distance_between_prefixes_ptr);
    int deleteLast = computeDistanceBetweenPrefixes(
        A, a_idx, B, b_idx - 1, distance_between_prefixes_ptr);
    distance_between_prefixes[a_idx][b_idx] =
        1 + min({substituteLast, addLast, deleteLast});
  }
  return distance_between_prefixes[a_idx][b_idx];
}

int LevenshteinDistance(string &A, string &B) {
  vector<vector<int>> v(A.size(), vector<int>(B.size(), -1));
  return computeDistanceBetweenPrefixes(A, (int)A.size() - 1, B,
                                        (int)B.size() - 1, &v);
}
int main() {
  string A = "orchestra";
  string B = "carthorse";
  int distance = LevenshteinDistance(A, B);
  cout << distance << endl;
}
