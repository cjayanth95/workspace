#include <iostream>
#include <memory>
using namespace std;
template <typename T> struct ListNode {
  T Val;
  shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverseSubList(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  if (start == finish)
    return L;
  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;
  int k = 1;
  while (k++ < start)
    sublist_head = sublist_head->next;
  // reverse sublist
  auto sublist_iter = sublist_head->next;
  while (start++ < finish) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }
  return dummy_head->next;
}

int reverseNumber(int N) {
  int reverse = 0;
  while (N % 10) {
    reverse = reverse * 10 + N % 10;
    N = N / 10;
  }
  return reverse;
}

shared_ptr<ListNode<int>> makeList(int _K) {
  int K = reverseNumber(_K);
  shared_ptr<ListNode<int>> dummy_head =
      make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  auto head = dummy_head;
  while (K % 10) {
    shared_ptr<ListNode<int>> tail =
        make_shared<ListNode<int>>(ListNode<int>{K % 10, nullptr});
    head->next = tail;
    head = tail;
    K = K / 10;
  }
  return dummy_head->next;
}

void PrintList(shared_ptr<ListNode<int>> L) {
  while (L) {
    cout << L->Val << endl;
    L = L->next;
  }
}

int main() {
  int k = 123456;
  shared_ptr<ListNode<int>> head = makeList(k); //ListNode <int> * head;
  shared_ptr<ListNode<int>> list = reverseSubList(head, 2, 5);
  PrintList(list);
}
