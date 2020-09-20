#include <cmath>
#include <iostream>
#include <limits>
#define int long long
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
int reverseInt(int n) {
  int result = 0;
  while (n) {
    result = result * 10 + n % 10;
    n /= 10;
  }
  cout << "result" << result << endl;
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

signed main() {
  int n = 1112223345;
  cout << numeric_limits<long>::max() << "n" << endl;
  cout << numeric_limits<long long>::max() << "n" << endl;
  ListNode *list = createListFromInt(n);
  ListNode *start, *end;
  start = list;
  end = list;
  while (end) {
    int startVal = start->val;
    while (start && (startVal == start->val)) {
      start = start->next;
    }
    if (start)
      end->next = start;
    end = start;
  }
  int out = printListNode(list);
  cout << out << endl;
  return out;
}
