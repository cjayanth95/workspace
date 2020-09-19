#include <stack>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
int reverseNumber(int n)
{
    int reversed = 0;
    while (n)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}
ListNode *createListNodeForNumber(int number)
{
    int lastDigit = number % 10;
    int rest = number / 10;
    ListNode *begin = new ListNode(lastDigit);
    ListNode *startPointer = begin;
    while (rest)
    {
        lastDigit = rest % 10;
        rest /= 10;
        ListNode *node = new ListNode(lastDigit);
        begin->next = node;
        node->next = nullptr;
        begin = node;
    }
    return startPointer;
}

int main()
{
    int number1 = 9;
    int number2 = 9;
    int reversed1 = reverseNumber(number1);
    int reversed2 = reverseNumber(number2);
    ListNode *node1 = createListNodeForNumber(reversed1);
    ListNode *node2 = createListNodeForNumber(reversed2);
    stack<int> s1;
    stack<int> s2;
    stack<int> outputSum;
    int carry = 0;
    while (node1 || node2)
    {
        if (node1)
        {
            s1.push(node1->val);
            node1 = node1->next;
        }
        if (node2)
        {
            s2.push(node2->val);
            node2 = node2->next;
        }
    }
    while (!s1.empty() || !s2.empty())
    {
        int currNode1 = 0;
        int currNode2 = 0;
        if (!s1.empty())
        {
            currNode1 = s1.top();
            s1.pop();
        }
        if (!s2.empty())
        {
            currNode2 = s2.top();
            s2.pop();
        }
        int sum = (currNode1 + currNode2 + carry) % 10;
        carry = (currNode1 + currNode2 + carry) / 10;
        outputSum.push(sum);
    }
    if (carry)
    {
        outputSum.push(carry);
    }
    ListNode *output = nullptr;
    ListNode *incrementPtr = nullptr;
    while(!outputSum.empty()){
        ListNode *newNode = new ListNode(outputSum.top());
        outputSum.pop();
        if (!output)
            output = newNode;
        if (!incrementPtr)
            incrementPtr = newNode;
        else
        {
            incrementPtr->next = newNode;
            incrementPtr = newNode;
        }
    }
    return 0;
}