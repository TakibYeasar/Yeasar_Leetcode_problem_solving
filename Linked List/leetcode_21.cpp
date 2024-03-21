
// Problem Link ====>>https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <iostream>
using namespace std;

struct

    ListNode
{

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        // Add the remaining nodes from either list, if any.
        cur->next = list1 != nullptr ? list1 : list2;

        return dummy->next;
    }
};

int main()
{
    // Create the first linked list
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Create the second linked list
    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);

    // Create a Solution object
    Solution solution;

    // Merge the two linked lists
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    cout << endl;

    // Delete the linked lists
    delete list1;
    delete list2;
    delete mergedList;

    return 0;
}