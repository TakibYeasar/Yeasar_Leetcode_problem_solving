# Problem Link ====>>https://leetcode.com/problems/partition-list/description/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        before = ListNode(0)
        before_curr = before
        after = ListNode(0)
        after_curr = after

        while head:
            if head.val < x:
                before_curr.next = head
                before_curr = head
            else:
                after_curr.next = head
                after_curr = head
            head = head.next

        after_curr.next = None  # Terminate the "after" list
        before_curr.next = after.next  # Connect the two lists

        return before.next


# Example usage
head = ListNode(1, ListNode(4, ListNode(
    3, ListNode(2, ListNode(5, ListNode(2))))))
partition_value = 3

solution = Solution()
partitioned_head = solution.partition(head, partition_value)

# Print the partitioned list
print("Partitioned list:", end=" ")
while partitioned_head:
    print(partitioned_head.val, end=" ")
    partitioned_head = partitioned_head.next

print()
