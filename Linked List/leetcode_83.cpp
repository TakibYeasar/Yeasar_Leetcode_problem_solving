// Problem Link ====>>https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include <iostream>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val = 0, ListNode *next = nullptr) : val(val), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *temp = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            if (prev == NULL)
            {
                prev = curr;
                temp = prev;
                curr = curr->next;
                continue;
            }
            if (curr->val == prev->val)
            {
                curr = curr->next;
                if (curr == NULL)
                    prev->next = NULL;
            }
            else
            {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return temp;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution s;
    ListNode *newHead = s.deleteDuplicates(head);

    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
