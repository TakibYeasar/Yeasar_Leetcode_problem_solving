# You are given the heads of two sorted linked lists list1 and list2.
# Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
# Return the head of the merged linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        """
        Merges two sorted linked lists into a single sorted linked list.

        Args:
            list1: A sorted linked list.
            list2: A sorted linked list.

        Returns:
            A sorted linked list containing all of the elements of list1 and list2.
        """

        dummy = ListNode(-1)
        cur = dummy

        while list1 and list2:
            if list1.val < list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next

        # Add the remaining nodes from either list, if any.
        cur.next = list1 if list1 else list2

        return dummy.next
