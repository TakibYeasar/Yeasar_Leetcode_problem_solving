// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is
// not a multiple of k then left - out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        int count = 0;
        while (curr != nullptr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count == k)
        {
            curr = reverseKGroup(curr, k);
            while (count-- > 0)
            {
                ListNode *temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        return head;
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

// Test function
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Change k value to test with different group sizes

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed list in groups of " << k << ": ";
    printList(head);

    return 0;
}