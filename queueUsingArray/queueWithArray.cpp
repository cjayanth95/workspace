#include <algorithm>
#include <deque>
#include <stdexcept>
#include <vector>

using namespace std;

class Queue {
public:
  explicit Queue(size_t capacity) : entries(capacity) {}
  size_t size() const { return num_queue_elements; }
  void Enqueue(int n) {
    if (num_queue_elements == entries.size()) {
      rotate(entries.begin(), entries.begin() + head, entries.end());
      head = 0;
      tail = num_queue_elements;
      entries.resize(entries.size() * kScaleFactor);
    }
    entries[tail] = n;
    tail = (tail + 1) % entries.size();
    ++num_queue_elements;
  }
  int Dequeue() {
    if (!entries.size())
      throw length_error("empty stack");
    int ret = entries[head];
    head = (head + 1) % entries.size();
    --num_queue_elements;
    return ret;
  }

private:
  vector<int> entries;
  const int kScaleFactor = 2;
  size_t head = 0, tail = 0, num_queue_elements = 0;
};
