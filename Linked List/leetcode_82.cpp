// Problem Link ====>>https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to handle potential head deletion
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            while (current->next != nullptr && current->val == current->next->val)
            {
                current = current->next; // Skip duplicates
            }

            if (prev->next == current)
            { // No duplicates found
                prev = prev->next;
            }
            else
            {
                prev->next = current->next; // Remove duplicates
            }

            current = current->next; // Move to the next node
        }

        return dummy->next; // Return the modified list
    }
};

int main()
{
    // Create a sample linked list with duplicates
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;                                   // Create an instance of the Solution class
    ListNode *newHead = solution.deleteDuplicates(head); // Call the function to remove duplicates

    // Print the modified list
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    cout << endl;

    return 0;
}
