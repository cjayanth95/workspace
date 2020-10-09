#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void sortApproximatelySorted(istringstream *s, int K) {
  int x;
  priority_queue<int, vector<int>, greater<>> min_heap;
  for (int i = 0; i < K; i++) {
    *s >> x;
    min_heap.emplace(x);
  }
  while (*s >> x) {
    cout << min_heap.top() << endl;
    min_heap.pop();
    min_heap.emplace(x);
  }
  while (!min_heap.empty()) {
    cout << min_heap.top()<<endl;
    min_heap.pop();
  }
}

int main() {
  string s = "3 -1 2 6 4 5 8";
  istringstream ss(s);
  sortApproximatelySorted(&ss, 2);
  return 0;
}
