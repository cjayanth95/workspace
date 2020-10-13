#include <memory>

using namespace std;

template <typename T> struct ListNode {
  T val;
  shared_ptr<ListNode<T>> next;
};

void AdvanceByK(shared_ptr<ListNode<int>> *L, int K) {
  while (K--) {
    *L = (*L)->next;
  }
}

int LengthOfList(shared_ptr<ListNode<int>> L) {
  int length = 0;
  while (L) {
    L = L->next;
  }
  return length;
}

shared_ptr<ListNode<int>> DetectCycleInLinkedList(shared_ptr<ListNode<int>> L) {
  shared_ptr<ListNode<int>> slow = L;
  shared_ptr<ListNode<int>> fast = L;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      int cycleLength = 0;
      do {
        fast = fast->next;
        ++cycleLength;
      } while (slow != fast);
      auto adv_iter = L;
      while (cycleLength--) {
        adv_iter = adv_iter->next;
      }
      auto adv_head = L;
      while (adv_head != adv_iter) {
        adv_head = adv_head->next;
        adv_iter = adv_iter->next;
      }
      return adv_iter;
    }
  }
  return nullptr;
}

shared_ptr<ListNode<int>>
OverlappingNoCycleLinkedList(shared_ptr<ListNode<int>> L1,
                             shared_ptr<ListNode<int>> L2) {
  int length1 = LengthOfList(L1);
  int length2 = LengthOfList(L2);
  AdvanceByK(L1 > L2 ? &L1 : &L2, abs(length1 - length2));
  while (L1 && L2 && (L1 != L2)) {
    L1 = L1->next;
    L2 = L2->next;
  }
  return L1;
}

int DistanceBetweenNodes(shared_ptr<ListNode<int>> L1,
                         shared_ptr<ListNode<int>> L2) {
  int distance = 0;
  while (L1 != L2) {
    L1 = L1->next;
    ++distance;
  }
  return distance;
}

shared_ptr<ListNode<int>>
OverlappingCycleLinkedList(shared_ptr<ListNode<int>> L1,
                           shared_ptr<ListNode<int>> L2) {
  auto root1 = DetectCycleInLinkedList(L1);
  auto root2 = DetectCycleInLinkedList(L2);
  if (!root1 && !root2)
    return OverlappingCycleLinkedList(L1, L2);
  else if ((root1 && !root2) || (root2 && !root1))
    return nullptr;
  auto temp = root2;
  do {
    temp = temp->next;
  } while (temp != root1 && temp != root2);
  if (temp != root1)
    return nullptr;
  int stemLength1 = DistanceBetweenNodes(L1, root1);
  int stemLength2 = DistanceBetweenNodes(L2, root2);
  AdvanceByK(stemLength1 > stemLength2 ? &L1 : &L2,
             abs(stemLength1 - stemLength2));
  while (L1 != L2 && L1 != root1 && L2 != root2) {
    L1 = L1->next;
    L2 = L2->next;
  }
  return L1 == L2 ? L1 : root1;
}
