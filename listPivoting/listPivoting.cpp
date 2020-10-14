#include <memory>

using namespace std;

template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

void AppendNode(shared_ptr<ListNode<int>> *node,
                shared_ptr<ListNode<int>> *tail) {
    //assuming tail is the tail node i.e tail->next == nullptr;
  (*tail)->next = *node;
  *tail = *node;
  *node = (*node)->next;
}

shared_ptr<ListNode<int>> ListPivot(shared_ptr<ListNode<int>> L, int k) {
  shared_ptr<ListNode<int>> less_head =
      make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  shared_ptr<ListNode<int>> greater_head =
      make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  shared_ptr<ListNode<int>> equal_head =
      make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  shared_ptr<ListNode<int>> less_iter = less_head;
  shared_ptr<ListNode<int>> equal_iter = equal_head;
  shared_ptr<ListNode<int>> greater_iter = greater_head;
  shared_ptr<ListNode<int>> iter = L;
  while (iter)
    AppendNode(&iter, iter->val > k
                          ? &greater_iter
                          : iter->val == k ? &equal_iter : &less_iter);
  greater_iter->next = nullptr;
  equal_iter->next = greater_head->next;
  less_iter->next = equal_head->next;
  return less_head->next;
}
