# You are given an array of k linked - lists lists, each linked - list is sorted in ascending order.
# Merge all the linked -lists into one sorted linked - list and return it.

# =======> merge sort
class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None

        while len(lists) != 1:
            merged_lists = []
            i = len(lists) - 1
            while i >= 1:
                merged_lists.append(self.merge(lists[i], lists[i - 1]))
                i -= 2

            if i == 0:
                merged_lists.append(lists[0])

            lists = merged_lists

        return lists[0]

    def merge(self, a, b):
        head = None
        ptr = None

        while a or b:
            if a and b:
                if a.val < b.val:
                    if not head:
                        head = a
                        ptr = head
                    else:
                        ptr.next = a
                        ptr = ptr.next

                    a = a.next
                else:
                    if not head:
                        head = b
                        ptr = head
                    else:
                        ptr.next = b
                        ptr = ptr.next

                    b = b.next
            elif a:
                if not head:
                    head = a
                    ptr = head
                else:
                    ptr.next = a
                    return head

                a = a.next
            else:
                if not head:
                    head = b
                    ptr = head
                else:
                    ptr.next = b
                    return head

        return head


def main():
    lists = []

    # Create the first linked list
    l1 = ListNode(1)
    l1.next = ListNode(4)
    l1.next.next = ListNode(5)

    # Create the second linked list
    l2 = ListNode(2)
    l2.next = ListNode(3)
    l2.next.next = ListNode(6)

    # Create the third linked list
    l3 = ListNode(8)
    l3.next = ListNode(9)

    # Add the linked lists to the vector
    lists.append(l1)
    lists.append(l2)
    lists.append(l3)

    solution = Solution()

    # Merge the k sorted linked lists
    merged_list = solution.mergeKLists(lists)

    # Print the merged list
    while merged_list:
        print(merged_list.val, end=" ")
        merged_list = merged_list.next

    print()

    # Delete the linked lists
    del l1, l2, l3, merged_list



# =========> Devide & conqure
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def mergeKLists(lists):
    if len(lists) == 0:
        return None
    return mergeKListsHelper(lists, 0, len(lists) - 1)


def mergeKListsHelper(lists, start, end):
    if start > end:
        return None
    if start == end:
        return lists[start]

    mid = start + (end - start) // 2
    left = mergeKListsHelper(lists, start, mid)
    right = mergeKListsHelper(lists, mid + 1, end)
    return merge(left, right)


def merge(list1Head, list2Head):
    dummyHead = Node(-1)
    dummyTail = dummyHead

    while list1Head and list2Head:
        if list1Head.val < list2Head.val:
            dummyTail.next = list1Head
            list1Head = list1Head.next
        else:
            dummyTail.next = list2Head
            list2Head = list2Head.next

        dummyTail = dummyTail.next

    dummyTail.next = list1Head if list1Head else list2Head
    return dummyHead.next


def main():
    lists = []

    # Create the first linked list
    l1 = Node(1)
    l1.next = Node(4)
    l1.next.next = Node(5)

    # Create the second linked list
    l2 = Node(2)
    l2.next = Node(3)
    l2.next.next = Node(6)

    # Create the third linked list
    l3 = Node(8)
    l3.next = Node(9)

    # Add the linked lists to the vector
    lists.append(l1)
    lists.append(l2)
    lists.append(l3)

    mergedList = mergeKLists(lists)

    while mergedList:
        print(mergedList.val, end=" ")
        mergedList = mergedList.next

    print()

    # Delete the linked lists


if __name__ == "__main__":
    main()



# ==========> priority queue

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def mergeKLists(lists):
    if len(lists) == 0:
        return None

    dummyHead = Node(-1)
    dummyTail = dummyHead

    pq = []
    for head in lists:
        if head:
            pq.append((head.val, head))

    heapq.heapify(pq)

    while pq:
        minNode = heapq.heappop(pq)[1]

        if minNode.next:
            heapq.heappush(pq, (minNode.next.val, minNode.next))

        dummyTail.next = minNode
        dummyTail = dummyTail.next

    return dummyHead.next


def main():
    lists = []

    # Create the first linked list
    l1 = Node(1)
    l1.next = Node(4)
    l1.next.next = Node(5)

    # Create the second linked list
    l2 = Node(2)
    l2.next = Node(3)
    l2.next.next = Node(6)

    # Create the third linked list
    l3 = Node(8)
    l3.next = Node(9)

    # Add the linked lists to the vector
    lists.append(l1)
    lists.append(l2)
    lists.append(l3)

    mergedList = mergeKLists(lists)

    while mergedList:
        print(mergedList.val, end=" ")
        mergedList = mergedList.next

    print()

    # Delete the linked lists


if __name__ == "__main__":
    main()



