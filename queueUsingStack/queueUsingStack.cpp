#include <stack>
#include <stdexcept>

using namespace std;

class Queue {
private:
  stack<int> enq, deq;

public:
  void Enqueue(int x) { enq.emplace(x); }
  int Dequeue() {
    if (deq.empty()) {
      while (!enq.empty()) {
        deq.push(enq.top());
        enq.pop();
      }
      if (deq.empty())
        throw length_error("empty stack");
    }
    int ret = deq.top();
    deq.pop();
    return ret;
  }
};
