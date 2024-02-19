// Given the head of a linked list and a value x, partition it such that all nodes 
// less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.


// =========>> Solution
// Approach: Two Pointer Technique with Dummy Nodes
// The idea is to use two pointers (or references) to create two separate linked lists:

// One for nodes with values less than x
// Another for nodes with values greater than or equal to x
// At the end, we can combine the two linked lists to get the desired result.

// Key Data Structures:
// Linked List: We work directly with the given linked list nodes.
// Dummy Nodes: Two dummy nodes are used to create the starting point for the two partitions.
// Step-by-step Breakdown:
// Initialization:

// Create two dummy nodes: before and after.
// Initialize two pointers before_curr and after_curr at the dummy nodes.
// Traversal & Partition:

// Traverse the linked list with the given head.
// For each node, if its value is less than x, attach it to the before list. Otherwise, attach it to the after list.
// Merging:

// After traversing the entire list, append the after list to the before list to form the partitioned linked list.
// Result:

// Return the next node of the before dummy node as the new head of the partitioned list.

// Complexity:
// Time Complexity: O(n)O(n)O(n)

// We traverse the linked list once, making the time complexity linear in the size of the list.
// Space Complexity: O(1)O(1)O(1)

// We use constant extra space since we are only creating two dummy nodes and reusing the existing nodes in the linked list.

#include<bits/stdc++.h>
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode before(0), after(0);
        ListNode *before_curr = &before;
        ListNode *after_curr = &after;

        while (head)
        {
            if (head->val < x)
            {
                before_curr->next = head;
                before_curr = head;
            }
            else
            {
                after_curr->next = head;
                after_curr = head;
            }
            head = head->next;
        }

        after_curr->next = nullptr;
        before_curr->next = after.next;

        return before.next;
    }
};

int main()
{
    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int partition_value = 3; // Choose the value for partitioning

    Solution solution;                                                      // Create an instance of the Solution class
    ListNode *partitioned_head = solution.partition(head, partition_value); // Partition the list

    // Print the partitioned list
    cout << "Partitioned list: ";
    while (partitioned_head != nullptr)
    {
        cout << partitioned_head->val << " ";
        partitioned_head = partitioned_head->next;
    }

    cout << endl;

    return 0;
}
