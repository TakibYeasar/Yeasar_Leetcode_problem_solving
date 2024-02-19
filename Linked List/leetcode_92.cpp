// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

// ===========> Solution
// Using Two Pointers (One-Pass)
// Intuition and Logic Behind the Solution
// In this efficient method, we employ two pointers to traverse and manipulate the linked list in one go. 
// The clever use of a dummy node helps us elegantly handle edge cases, and tuple unpacking makes the code more Pythonic and straightforward.

// Step-by-step Explanation
// Initialization:

// Create a dummy node and connect its next to the head of the list.
// Initialize a prev pointer to the dummy node.
// Move to Start Position:

// Traverse the list until the node just before the left-th node is reached.
// Execute Sublist Reversal:

// Use a current pointer to keep track of the first node in the sublist.
// Reverse the sublist nodes using prev and current.
// Link Back:

// Automatically link the reversed sublist back into the original list.
// Complexity Analysis
// Time Complexity: O(n) — A single traversal does the job.
// Space Complexity: O(1) — Smart pointer manipulation eliminates the need for additional data structures.

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
    {
        return head; // No need to reverse if left and right are the same
    }

    ListNode *dummy = new ListNode(0); // Dummy node to handle potential head changes
    dummy->next = head;

    ListNode *prev = dummy;
    for (int i = 0; i < left - 1; ++i)
    {
        prev = prev->next;
    }

    ListNode *start = prev->next;
    ListNode *then = start->next;

    for (int i = left; i < right; ++i)
    {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy->next;
}

int main()
{
    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    ListNode *reversedHead = reverseBetween(head, left, right);

    // Print the reversed list
    cout << "Reversed list: ";
    while (reversedHead != nullptr)
    {
        cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }

    cout << endl;

    return 0;
}
