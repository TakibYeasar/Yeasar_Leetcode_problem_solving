# Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
# Return the linked list sorted as well.


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """
        Removes duplicates from a sorted linked list.

        Args:
            head: The head of the linked list.

        Returns:
            The head of the linked list without duplicates.
        """

        # Check if the input linked list is empty.
        if head is None:
            return head

        # Initialize two pointers, `current` and `next`.
        current = head
        next = head.next

        # Iterate over the linked list.
        while next is not None:
            # If the current node and next node have the same value,
            # delete the next node.
            if current.val == next.val:
                current.next = next.next
                del next
                next = current.next
            # Otherwise, move the current node forward one position.
            else:
                current = current.next
                next = next.next

        # Return the head of the linked list without duplicates.
        return head

