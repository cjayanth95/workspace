#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> ComputeKLargestInMaxHeap(vector<int> &A, int K) {
  struct HeapEntry {
    int idx;
    int value;
  };
  if (K < 0)
    return {};
  priority_queue<HeapEntry, vector<HeapEntry>,
                 function<bool(HeapEntry, HeapEntry)>>
  max_heap([](const HeapEntry &h1, const HeapEntry &h2) -> bool {
    return h1.value < h2.value;
  });
  max_heap.emplace(HeapEntry{0, A[0]});
  vector<int> result;
  for (int i = 0; i < K; i++) {
    int candidate_idx = max_heap.top().idx;
    result.emplace_back(max_heap.top().value);
    max_heap.pop();
    int left_child_idx = 2 * candidate_idx + 1;
    int right_child_idx = left_child_idx + 1;
    if (left_child_idx < (int)A.size())
      max_heap.emplace(HeapEntry{left_child_idx, A[left_child_idx]});
    if (right_child_idx < (int)A.size())
      max_heap.emplace(HeapEntry{right_child_idx, A[right_child_idx]});
  }
  return result;
};
void PrintVector(const vector<int> &A) {
  for (int i : A)
    cout << i << endl;
};
int main() {
  vector<int> v{561, 314, 401, 28, 156, 359, 271, 11, 3};
  vector<int> res = ComputeKLargestInMaxHeap(v, 3);
  PrintVector(res);
  return 0;
}
