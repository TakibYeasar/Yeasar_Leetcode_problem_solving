// Problem Link ====>>https://leetcode.com/problems/partition-list/description/

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
