# Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
# leaving only distinct numbers from the original list. Return the linked list sorted as well.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # Dummy node to handle potential head deletion
        dummy = ListNode(0, head)
        prev = dummy
        curr = head

        while curr:
            while curr.next and curr.val == curr.next.val:
                curr = curr.next  # Skip duplicates

            if prev.next == curr:  # No duplicates found
                prev = prev.next
            else:
                prev.next = curr.next  # Remove duplicates

            curr = curr.next  # Move to the next node

        return dummy.next  # Return the modified list


# Example usage
head = ListNode(1, ListNode(2, ListNode(2, ListNode(3, ListNode(3)))))
solution = Solution()
new_head = solution.deleteDuplicates(head)

# Print the modified list
while new_head:
    print(new_head.val, end=" ")
    new_head = new_head.next

print()
