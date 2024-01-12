# Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
# k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is
# not a multiple of k then left - out nodes, in the end, should remain as it is.
# You may not alter the values in the list's nodes, only nodes themselves may be changed.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseKGroup(head, k):
    def reverseLinkedList(start, end):
        prev, curr = None, start
        while curr != end:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        return prev

    if not head or k == 1:
        return head

    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while head:
        tail = prev
        for i in range(k):
            tail = tail.next
            if not tail:
                return dummy.next

        next_temp = tail.next
        head, tail = reverseLinkedList(head, tail)

        prev.next = head
        tail.next = next_temp
        prev = tail
        head = next_temp

    return dummy.next

# Function to print the linked list


def printList(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


# Test function
if __name__ == "__main__":
    # Create a sample linked list
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    k = 2  # Change k value to test with different group sizes

    print("Original list:", end=" ")
    printList(head)

    head = reverseKGroup(head, k)

    print(f"Reversed list in groups of {k}: ", end="")
    printList(head)
