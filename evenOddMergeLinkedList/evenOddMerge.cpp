#include <array>
#include <memory>

using namespace std;

template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> evenOddMerge(shared_ptr<ListNode<int>> L) {
  auto dummy_even_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  auto dummy_odd_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  array<shared_ptr<ListNode<int>>, 2> dummy_pair{dummy_even_head,
                                                 dummy_odd_head};
  int turn = 0;
  for (auto iter = L; iter; iter = iter->next) {
    dummy_pair[turn]->next = iter;
    dummy_pair[turn] = dummy_pair[turn]->next;
    turn ^= 1;
  }
  dummy_pair[1]->next = nullptr;
  dummy_pair[0]->next = dummy_odd_head->next;
  return dummy_even_head->next;
}
