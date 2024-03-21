
// Problem Link ====>> https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Creating two linked lists
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "First linked list: ";
    printLinkedList(l1);

    cout << "Second linked list: ";
    printLinkedList(l2);

    // Adding two linked lists
    ListNode *result = solution.addTwoNumbers(l1, l2);

    cout << "Result of addition: ";
    printLinkedList(result);

    // Cleanup: Freeing memory allocated to the linked lists
    ListNode *temp;
    while (l1 != nullptr)
    {
        temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr)
    {
        temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (result != nullptr)
    {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}