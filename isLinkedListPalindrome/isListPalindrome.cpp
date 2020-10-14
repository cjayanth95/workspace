#include <memory>

using namespace std;

template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverseLinkedList(shared_ptr<ListNode<int>> L) {
  shared_ptr<ListNode<int>> dummy_head =
      make_shared<ListNode<int>>(ListNode<int>{0, L});
  int length = 10; // length of list
  auto head = dummy_head;
  auto iter = dummy_head->next;
  while (length--) {
    auto temp = iter->next;
    iter->next = temp->next;
    dummy_head->next = iter->next;
    head->next = temp;
  }
  return dummy_head->next;
}

bool IsLinkedListPalindrome(shared_ptr<ListNode<int>> L) {
  if (L == nullptr)
    return true;
  auto fast = L;
  auto slow = L;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  auto reverse = reverseLinkedList(slow);
  auto head = L;
  while (head && reverse) {

    if (head->val != reverse->val)
      return false;
    head = head->next;
    reverse = reverse->next;
  }
  return true;
}
