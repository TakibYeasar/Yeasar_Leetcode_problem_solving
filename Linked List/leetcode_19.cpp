
// Problem Link ====>>https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n)
        {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *first = dummy;
            ListNode *second = dummy;

            for (int i = 1; i <= n + 1; ++i)
            {
                first = first->next;
            }

            while (first != nullptr)
            {
                first = first->next;
                second = second->next;
            }

            second->next = second->next->next;
            return dummy->next;
        }
};

int main()
{
    // Create the linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a Solution object
    Solution solution;

    // Remove the nth node from the end
    int n = 2;
    ListNode *newHead = solution.removeNthFromEnd(head, n);

    // Print the new linked list
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    cout << endl;

    // Delete the linked list
    delete head;
    delete newHead;

    return 0;
}