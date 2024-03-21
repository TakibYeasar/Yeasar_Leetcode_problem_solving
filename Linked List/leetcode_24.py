# Problem Link ====>>https://leetcode.com/problems/swap-nodes-in-pairs/description/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # Create a dummy node to simplify the code
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next

            # Swap nodes
            first.next = second.next
            second.next = first
            prev.next = second

            # Move to the next pair
            prev = first

        return dummy.next

# Function to print the linked list


def printList(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


# Example usage
# Create a sample linked list: 1 -> 2 -> 3 -> 4
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)

sol = Solution()
print("Original list: ", end="")
printList(head)

# Swap nodes in pairs
head = sol.swapPairs(head)

print("List after swapping pairs: ", end="")
printList(head)
