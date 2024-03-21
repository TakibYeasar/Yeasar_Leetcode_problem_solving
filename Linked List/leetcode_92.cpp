// Problem Link ====>>https://leetcode.com/problems/reverse-linked-list-ii/description/

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
