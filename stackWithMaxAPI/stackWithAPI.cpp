#include <list>
#include <math.h>
#include <new>
#include <stack>
#include <stdexcept>

using namespace std;

class Stack {
private:
  struct MaxElementWithCount {
    int max;
    int count;
  };
  stack<MaxElementWithCount> element_with_cached_max;
  stack<int> element_;

public:
  bool Empty() const { return element_.empty(); }
  int Max() const {
    if (Empty())
      throw length_error("stack empty");
    int pop_element = element_with_cached_max.top().max;
    return pop_element;
  }
  void Push(int x) {
    element_.emplace(x);
    if (element_with_cached_max.empty()) {
      element_with_cached_max.emplace(MaxElementWithCount{x, 1});
    } else {
      int max = element_with_cached_max.top().max;
      if (max == x) {
        int &maxCount = element_with_cached_max.top().max;
        ++maxCount;
      } else if (x > max) {
        element_with_cached_max.emplace(MaxElementWithCount{x, 1});
      }
    }
    element_with_cached_max.emplace(
        MaxElementWithCount{x, max(x, Empty() ? x : Max())});
  }
  int Pop() {
    if (Empty())
      throw length_error("stack empty");
    int pop_element = element_.top();
    element_.pop();
    int max = element_with_cached_max.top().max;
    if (pop_element == max) {
      int &maxCount = element_with_cached_max.top().max;
      --maxCount;
      if (maxCount == 0)
        element_with_cached_max.pop();
    }
    return pop_element;
  }
};

int main() { return 0; }
