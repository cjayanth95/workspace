#include <memory>

using namespace std;
template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> cyclicShiftByK(shared_ptr<ListNode<int>> L, int K) {
  if (L == nullptr)
    return L;
  auto head = L;
  int n = 1;
  while (head->next) {
    head = head->next;
    ++n;
  }
  K %= n;
  if (K == 0)
    return L;
  int shift = n - K;
  head->next = L;
  auto new_head = head;
  while (shift--) {
    new_head = new_head->next;
  }
  auto new_tail = new_head->next;
  new_head->next = nullptr;
  return new_tail;
}
