#include <iostream>
#include <vector>
using namespace std;

int combinationForFinalScore(const vector<int> &individual_play_scores,
                             int finalScore) {
  vector<vector<int>> num_combinations_for_score(
      individual_play_scores.size(), vector<int>(finalScore + 1, 0));
  for (int i = 0; i < (int)individual_play_scores.size(); i++) {
    num_combinations_for_score[i][0] = 1;
    for (int j = 1; j <= finalScore; j++) {
      int without_this_play = i >= 1 ? num_combinations_for_score[i - 1][j] : 0;
      int with_this_play =
          j >= individual_play_scores[i]
              ? num_combinations_for_score[i][j - individual_play_scores[i]]
              : 0;
      num_combinations_for_score[i][j] = with_this_play + without_this_play;
    }
  }
  return num_combinations_for_score.back().back();
}

int main() {
  vector<int> individual_play_scores{2, 3, 7};
  int finalScore = 12;
  int combination =
      combinationForFinalScore(individual_play_scores, finalScore);
  cout << combination << endl;
  return 0;
}
