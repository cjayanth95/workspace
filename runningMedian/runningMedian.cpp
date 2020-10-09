#include <functional>
#include <iostream>
#include <queue>

#include <sstream>
using namespace std;

vector<double> runningMedian(istringstream *s) {
  int buf;
  priority_queue<int, vector<int>, greater<>> min_heap;
  priority_queue<int, vector<int>, less<>> max_heap;
  vector<double> onlineMedian;
  while (*s >> buf) {
    if (min_heap.empty())
      min_heap.emplace(buf);
    else {
      if (min_heap.top() > buf)
        max_heap.emplace(buf);
      else
        min_heap.emplace(buf);
      if (min_heap.size() > max_heap.size() + 1) {
        max_heap.emplace(min_heap.top());
        min_heap.pop();
      } else if (max_heap.size() > min_heap.size()) {
        min_heap.emplace(max_heap.top());
        max_heap.pop();
      }
      if (min_heap.size() == max_heap.size())
        onlineMedian.emplace_back(0.5 * min_heap.top() + 0.5 * max_heap.top());
      else
        onlineMedian.emplace_back(min_heap.top());
    }
  }
  return onlineMedian;
}
void print(vector<double> v) {
  for (double d : v)
    cout << d << endl;
}

int main() {
  string runningInts = "1 0 3 5 2 0 1";
  istringstream s(runningInts);
  vector<double> onlineMedian = runningMedian(&s);
  print(onlineMedian);
  return 0;
}
