#include <vector>

#include <iostream>
#include <stdio.h>
using namespace std;


void next_permutation(vector<int> &A) {
  int N = A.size();
  int i = N - 1;
  while (i > 0 && A[i] <= A[i - 1])
    i--;
  if (i == 0) {
    reverse(A.begin(), A.end());
    return;
  }
  int t = i - 1;
  int k = A[i - 1];
  while (i < N && k < A[i])
    i++;
  swap(A[t], A[i-1]);
  reverse(A.begin() + t+1, A.end());
}
bool testNextPermutation(vector<int>&A, vector<int>&expectedA){
    next_permutation(A);
    int N  = A.size();
    for(int i = 0; i< N ;i++){
        if(A[i]!=expectedA[i]) return false;
    }
    return true;
}
int main() {
  vector<int> A{6, 2, 1, 5, 4, 3, 0};
  vector<int> expectedA{6, 2, 3, 0, 1, 4, 5};
  vector<int> B{5,1,1};
  vector<int> expectedB{1,1,5};

  cout<<"test case 1: "<<testNextPermutation(A,expectedA)<<endl;;
  cout<<"test case 2: "<<testNextPermutation(B,expectedB)<<endl;
  return 0;
}
