# Problem Link ====>>https://leetcode.com/problems/merge-two-sorted-lists/description/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        dummy = ListNode(-1)
        curr = dummy

        while list1 and list2:
            if list1.val < list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next

            curr = curr.next

        # Add remaining nodes from either list, if any
        curr.next = list1 or list2

        return dummy.next


# Create the first linked list
list1 = ListNode(1)
list1.next = ListNode(3)
list1.next.next = ListNode(5)

# Create the second linked list
list2 = ListNode(2)
list2.next = ListNode(4)

# Create a Solution object
solution = Solution()

# Merge the two linked lists
merged_list = solution.mergeTwoLists(list1, list2)

# Print the merged list
while merged_list:
    print(merged_list.val, end=" ")
    merged_list = merged_list.next

print()

# Delete the linked lists
del list1, list2, merged_list
