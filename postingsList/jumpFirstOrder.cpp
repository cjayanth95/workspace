#include <memory>
#include <stack>

using namespace std;

template <typename T> struct PostingsListNode {
  T order;
  shared_ptr<PostingsListNode<T>> jump;
  shared_ptr<PostingsListNode<T>> next;
};

void SetJumpHelper(const shared_ptr<PostingsListNode<int>> &L, int *order) {
  stack<shared_ptr<PostingsListNode<int>>> s;
  s.emplace(L);
  L->order = *order;
  while (!s.empty()) {
    auto top = s.top();
    s.pop();
    if (top && top->order == -1) {
      top->order = (*order)++;
      s.emplace(top->jump);
      s.emplace(top->next);
    }
  }
}

void SetJumpOrder(const shared_ptr<PostingsListNode<int>> &L) {
  int order = 0;
  SetJumpHelper(L, &order);
}
