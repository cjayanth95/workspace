struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;

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
    int number1 = 10;
    int number2 = 10;
    ListNode *node1 = createListNodeForNumber(number1);
    ListNode *node2 = createListNodeForNumber(number2);
    int carry = 0;
    ListNode *output = nullptr;
    ListNode *incrementPtr = nullptr;
    while (node1 || node2)
    {
        int currNode1 = 0;
        int currNode2 = 0;
        if (node1)
            currNode1 = node1->val;
        if (node2)
            currNode2 = node2->val;
        int sum = (currNode1 + currNode2 + carry) % 10;
        carry = (currNode1 + currNode2 + carry) / 10;
        ListNode *newNode = new ListNode(sum);
        if (!output)
            output = newNode;
        if (!incrementPtr)
            incrementPtr = newNode;
        else
        {
            incrementPtr->next = newNode;
            incrementPtr = newNode;
        }
        if (node1)
            node1 = node1->next;
        if (node2)
            node2 = node2->next;
    }
    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        incrementPtr->next = newNode;
    }
    return 0;
}