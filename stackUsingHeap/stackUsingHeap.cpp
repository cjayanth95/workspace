#include <list>
#include <vector>

#include <queue>

using namespace std;

class Stack {

public:
  void push(int x) { max_heap.emplace(valueWithRank{x, timestamp_++}); };
  int pop() {
    if (max_heap.empty())
      throw __throw_length_error;
    int val = max_heap.top().value;
    max_heap.pop();
    return val;
  }
  int peek() const { return max_heap.top().value; }

private:
  int timestamp_ = 0;
  struct valueWithRank {
    int value;
    int timeStamp;
    bool operator<(const valueWithRank &v2) {
      return timeStamp < v2.timeStamp;
    };
  };
  priority_queue<valueWithRank, vector<valueWithRank>, less<>> max_heap;
};
