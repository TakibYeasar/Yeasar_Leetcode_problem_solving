// Given a linked list, swap every two adjacent nodes and return its head.You must solve the problem without modifying
// the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <bits/stdc++.h>
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
    ListNode *swapPairs(ListNode *head)
    {
        // Create a dummy node to simplify the code
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;

            // Swap nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy->next;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    cout << "Original list: ";
    printList(head);

    // Swap nodes in pairs
    head = sol.swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(head);

    // Free memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
