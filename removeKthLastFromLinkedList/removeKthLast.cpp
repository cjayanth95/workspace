#include <memory>

using namespace std;
template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> removeKthLast(shared_ptr<ListNode<int>> L, int K) {
  shared_ptr<ListNode<int>> dummy_head =
      make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto head = dummy_head;
  auto iter = L;
  while (K--) {
    iter = iter->next;
  }
  while (iter) {
    iter = iter->next;
    head = head->next;
  }
  head->next = head->next->next;
  return dummy_head->next;
}
