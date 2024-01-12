# Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
# Return the linked list sorted as well.


class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head):
        if not head or not head.next:
            return head

        prev = None
        temp = None
        curr = head

        while curr:
            if not prev:
                prev = curr
                temp = prev
                curr = curr.next
                continue

            if curr.val == prev.val:
                curr = curr.next
                if not curr:
                    prev.next = None
            else:
                prev.next = curr
                prev = curr
                curr = curr.next

        return temp


def main():
    head = ListNode(1)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(3)

    solution = Solution()
    newHead = solution.deleteDuplicates(head)

    while newHead:
        print(newHead.val, end=" ")
        newHead = newHead.next

    print()
