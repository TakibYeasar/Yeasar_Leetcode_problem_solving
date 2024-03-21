# Problem Link ====>>https://leetcode.com/problems/reverse-linked-list-ii/description/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseBetween(head: ListNode, left: int, right: int) -> ListNode:
    if left == right:
        return head  # No need to reverse if left and right are the same

    dummy = ListNode(0)  # Dummy node to handle potential head changes
    dummy.next = head
    prev = dummy

    for _ in range(left - 1):
        prev = prev.next

    start = prev.next
    then = start.next

    for _ in range(left, right):
        start.next = then.next
        then.next = prev.next
        prev.next = then
        then = start.next

    return dummy.next


# Example usage
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
left = 2
right = 4

reversed_head = reverseBetween(head, left, right)

# Print the reversed list
print("Reversed list:", end=" ")
while reversed_head:
    print(reversed_head.val, end=" ")
    reversed_head = reversed_head.next

print()
