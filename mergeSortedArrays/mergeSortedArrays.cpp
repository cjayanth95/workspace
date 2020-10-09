#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd &that) const {
    return *current > *(that.current);
  }
  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};
void printVector(vector<int> v) {
  for (int i : v) {
    cout << i << endl;
  }
}
vector<int> mergeSortedArrays(const vector<vector<int>> &sortedArrays) {
  priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>,
                 greater<>>
      minheap;
  for (const vector<int> &sortedArray : sortedArrays) {
    if (!sortedArrays.empty()) {
      minheap.emplace(
          IteratorCurrentAndEnd{sortedArray.cbegin(), sortedArray.cend()});
    }
  }
  vector<int> result;
  while (!minheap.empty()) {
    auto smallestArray = minheap.top();
    minheap.pop();
    if (smallestArray.current != smallestArray.end) {
      result.emplace_back(*(smallestArray.current));
      minheap.emplace(IteratorCurrentAndEnd{next(smallestArray.current),
                                            smallestArray.end});
    }
  }
  return result;
}
int main() {
  vector<vector<int>> sortedArays;
  sortedArays.push_back({3, 5, 7});
  sortedArays.push_back({0, 6});
  sortedArays.push_back({0, 28});
  vector<int> result = mergeSortedArrays(sortedArays);
  printVector(result);
  return 0;
}
