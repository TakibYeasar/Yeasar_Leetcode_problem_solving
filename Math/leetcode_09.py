# Given an integer x, return true if x is a palindrome, and false otherwise.


class Solution:
  def isPalindrome(self, x: int) -> bool:
    """Returns True if the given number is a palindrome, False otherwise."""
    if x < 0:
      return False

    reversed_x = 0
    while x > 0:
      reversed_x = reversed_x * 10 + x % 10
      x //= 10

    return reversed_x == x
