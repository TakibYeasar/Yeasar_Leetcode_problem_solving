# You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order,
# and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
# You may assume the two numbers do not contain any leading zero,except the number 0 itself.

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    dummyHead = ListNode(0)
    tail = dummyHead
    carry = 0

    while l1 is not None or l2 is not None or carry != 0:
      digit1 = l1.val if l1 is not None else 0
      digit2 = l2.val if l2 is not None else 0

      sum = digit1 + digit2 + carry
      digit = sum % 10
      carry = sum // 10

      newNode = ListNode(digit)
      tail.next = newNode
      tail = tail.next

      l1 = l1.next if l1 is not None else None
      l2 = l2.next if l2 is not None else None

    result = dummyHead.next
    dummyHead.next = None
    return result

def main():
  l1 = ListNode(2)
  l1.next = ListNode(4)
  l1.next.next = ListNode(3)

  l2 = ListNode(5)
  l2.next = ListNode(6)
  l2.next.next = ListNode(4)

  solution = Solution()
  result = solution.addTwoNumbers(l1, l2)

  while result:
    print(result.val, end=" ")
    result = result.next
  print()

if __name__ == "__main__":
  main()
