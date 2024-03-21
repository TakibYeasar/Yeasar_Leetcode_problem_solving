
# Problem Link ====>>https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy

        for i in range(1, n + 1):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next
        return dummy.next


def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    solution = Solution()
    n = 2
    newHead = solution.removeNthFromEnd(head, n)

    while newHead:
        print(newHead.val, end=" ")
        newHead = newHead.next

    print()

    del head
    del newHead


if __name__ == "__main__":
    main()
