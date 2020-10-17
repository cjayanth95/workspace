#include <list>
#include <math.h>
#include <new>
#include <stack>

using namespace std;

class Stack {
private:
  struct MaxElementWithCache {
    int element;
    int max;
  };
  stack<MaxElementWithCache> element_with_cached_max;

public:
  bool Empty() const { return element_with_cached_max.empty(); }
  int Max() const {
    if (Empty())
      throw __throw_length_error;
    int pop_element = element_with_cached_max.top().max;
    return pop_element;
  }
  void Push(int x) {
    element_with_cached_max.emplace(
        MaxElementWithCache{x, max(x, Empty() ? x : Max())});
  }
  int Pop() {
    if (Empty())
      throw __throw_length_error;
    int pop_element = element_with_cached_max.top().element;
    element_with_cached_max.pop();
    return pop_element;
  }
};

int main() { return 0; }
