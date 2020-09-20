#include <cmath>
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
int reverseInt(int n) {
  int result = 0;
  while (n) {
    result = result * 10 + n % 10;
    n /= 10;
  }
  return result;
}
ListNode *createListFromInt(int n) {
  int reverse = reverseInt(n);
  ListNode *dummy = new ListNode(-1);
  ListNode *start = new ListNode(reverse % 10);
  dummy->next = start;
  reverse /= 10;
  while (reverse) {
    ListNode *node = new ListNode(reverse % 10);
    start->next = node;
    start = node;
    reverse /= 10;
  }
  return dummy->next;
}
ListNode *getNthNode(ListNode *node, int n) {
  while (--n) {
    node = node->next;
  }
  return node;
}
int lengthOfList(ListNode *list) {

  ListNode *iter = list;
  int lengthOfList = 0;

  while (iter) {
    iter = iter->next;
    lengthOfList++;
  }
  return lengthOfList;
}
int printListNode(ListNode *node) {
  int length = lengthOfList(node);
  int val = 0;
  while (node) {
    val += (node->val) * pow(10, --length);
    node = node->next;
  }
  return val;
}

using namespace std;
int main() {
  int n = 12345;
  int k = 4;
  ListNode *list = createListFromInt(n);
  ListNode *iter = list;
  ListNode *last = nullptr;
  int lengthOfList = 0;
  while (iter) {
    if (iter->next == NULL)
      last = iter;
    iter = iter->next;
    lengthOfList++;
  }
  k %= lengthOfList;
  if (!k || lengthOfList <= 1)
    return 0;
  last->next = list;
  iter = list;

  ListNode *nthNode = getNthNode(iter, lengthOfList - k);
  iter = nthNode->next;

  nthNode->next = NULL;
  int out = printListNode(iter);
  cout << out << endl;
  return out;
}
