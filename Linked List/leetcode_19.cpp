// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include <iostream>
using namespace std;

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
