#include <memory>

using namespace std;
template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>> &head) {
  shared_ptr<ListNode<int>> slow = head, fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      int cycle_length = 0;
      do {
        fast = fast->next;
        ++cycle_length;
      } while (slow != fast);

      auto cycle_length_adv_itr = head;
      while (cycle_length--) {
        cycle_length_adv_itr = cycle_length_adv_itr->next;
      }
      auto iter = head;
      while (iter != cycle_length_adv_itr) {
        iter = iter->next;
        cycle_length_adv_itr = cycle_length_adv_itr->next;
      }
      return iter;
    }
  }
  return nullptr;
}
