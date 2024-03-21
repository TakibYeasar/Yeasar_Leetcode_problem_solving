
// Problem Link ====>>https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

// =======> merge sort

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (!lists.size())
            return nullptr;
        while (lists.size() != 1)
        {
            vector<ListNode *> k;
            int i = lists.size() - 1;
            for (; i >= 1; i -= 2)
            {
                ListNode *temp = merge(lists[i], lists[i - 1]);
                k.push_back(temp);
            }
            if (i == 0)
                k.push_back(lists[0]);
            lists = k;
        }
        return lists[0];
    }

private:
    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *head;

        if (a && b)
        {
            if (a->val < b->val)
            {
                head = a;
                a = a->next;
            }
            else
            {
                head = b;
                b = b->next;
            }
        }
        else if (a)
        {
            return a;
        }
        else
        {
            return b;
        }

        ListNode *ptr = head;

        while (a || b)
        {
            if (a && b)
            {
                if (a->val < b->val)
                {
                    ptr->next = a;
                    ptr = ptr->next;
                    a = a->next;
                }
                else
                {
                    ptr->next = b;
                    ptr = ptr->next;
                    b = b->next;
                }
            }
            else if (a)
            {
                ptr->next = a;
                return head;
            }
            else
            {
                ptr->next = b;
                return head;
            }
        }

        return head;
    }
};

int main()
{
    // Create a vector of linked lists
    vector<ListNode *> lists;

    // Create the first linked list
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Create the second linked list
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(6);

    // Create the third linked list
    ListNode *l3 = new ListNode(8);
    l3->next = new ListNode(9);

    // Add the linked lists to the vector
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Create a Solution object
    Solution solution;

    // Merge the k sorted linked lists
    ListNode *mergedList = solution.mergeKLists(lists);

    // Print the merged list
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    cout << endl;

    // Delete the linked lists
    delete l1;
    delete l2;
    delete l3;
    delete mergedList;

    return 0;
}

// =========> Devide & conqure
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        if (start == end)
        {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode *left = mergeKListsHelper(lists, start, mid);
        ListNode *right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *merge(ListNode *list1Head, ListNode *list2Head)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        while (list1Head != NULL && list2Head != NULL)
        {
            if (list1Head->val < list2Head->val)
            {
                dummyTail->next = list1Head;
                list1Head = list1Head->next;
            }
            else
            {
                dummyTail->next = list2Head;
                list2Head = list2Head->next;
            }
            dummyTail = dummyTail->next;
        }

        dummyTail->next = (list1Head != NULL) ? list1Head : list2Head;
        return dummyHead->next;
    }
};

int main()
{
    // Create a vector of linked lists
    vector<ListNode *> lists;

    // Create the first linked list
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Create the second linked list
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(6);

    // Create the third linked list
    ListNode *l3 = new ListNode(8);
    l3->next = new ListNode(9);

    // Add the linked lists to the vector
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Create a Solution object
    Solution solution;

    // Merge the k sorted linked lists
    ListNode *mergedList = solution.mergeKLists(lists);

    // Print the merged list
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    cout << endl;

    // Delete the linked lists
    delete l1;
    delete l2;
    delete l3;
    delete mergedList;

    return 0;
}

// ==========> priority queue

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }

        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for (auto head : lists)
        {
            if (head != NULL)
            {
                pq.push({head->val, head});
            }
        }

        while (!pq.empty())
        {
            ListNode *minNode = pq.top().second;
            pq.pop();

            if (minNode->next != NULL)
            {
                pq.push({minNode->next->val, minNode->next});
            }

            dummyTail->next = minNode;
            dummyTail = dummyTail->next;
        }

        return dummyHead->next;
    }
};

int main()
{
    // Create a vector of linked lists
    vector<ListNode *> lists;

    // Create the first linked list
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Create the second linked list
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(6);

    // Create the third linked list
    ListNode *l3 = new ListNode(8);
    l3->next = new ListNode(9);

    // Add the linked lists to the vector
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Create a Solution object
    Solution solution;

    // Merge the k sorted linked lists
    ListNode *mergedList = solution.mergeKLists(lists);

    // Print the merged list
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    cout << endl;

    // Delete the linked lists
    delete l1;
    delete l2;
    delete l3;
    delete mergedList;

    return 0;
}
