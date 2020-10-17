#include <algorithm>
#include <list>
#include <stdexcept>

using namespace std;

class Queue {
public:
  void Enque(int x) { queue.emplace_back(x); }
  int Dequeue() {
    if (queue.empty())
      throw length_error("empty queue");
    int val = queue.front();
    return val;
  }
  int Max() const {
    if (queue.empty())
      throw length_error("empty queue");
    return *max_element(queue.begin(), queue.end());
  }

private:
  list<int> queue;
};
