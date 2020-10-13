#include <memory>

using namespace std;

template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

int LengthOfList(shared_ptr<ListNode<int>> L) {
  int length = 0;
  while (L) {
    ++length;
    L = L->next;
  }
  return length;
}

void AdvanceByK(shared_ptr<ListNode<int>> *L, int K) {
  while (K--) {
    *L = (*L)->next;
  }
}
shared_ptr<ListNode<int>> OverlappingNoCycleList(shared_ptr<ListNode<int>> L1,
                                                 shared_ptr<ListNode<int>> L2) {

  int length1 = LengthOfList(L1);
  int length2 = LengthOfList(L2);
  AdvanceByK(length1 > length2 ? &L1 : &L2, abs(length1 - length2));
  while (L1 && L2 && L1 != L2) {
    L1 = L1->next;
    L2 = L2->next;
  }
  return L1;
}
