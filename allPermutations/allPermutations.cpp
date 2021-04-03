
#include <vector>

#include <iostream>
#include <stdio.h>
using namespace std;

void allPermutations(vector<int> &A, int start, vector<vector<int>> &result) {
  int N = A.size();
  if (start == N - 1) {
    result.emplace_back(A);
    return;
  }
  for (int i = start ; i < N; i++) {
    vector<int> B = A;
    swap(B[i], B[start]);
    allPermutations(B, start + 1, result);
  }
}

int main() {
    vector<int>A{1,2,3,4};
    vector<vector<int>>result;
    allPermutations(A, 0, result);
    cout<<result.size()<<endl;
    for(auto i: result){
        for(auto k:i) cout<<" "<<k;
        cout<<""<<endl;
    }

}
