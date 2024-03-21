
# Problem Link ====>> https://leetcode.com/problems/palindrome-number/description/


class Solution:
  def isPalindrome(self, x: int) -> bool:
    if x < 0:
      return False

    reversedNumber = 0
    temp = x

    while temp != 0:
      reversedNumber = reversedNumber * 10 + temp % 10
      temp //= 10

    return reversedNumber == x


if __name__ == "__main__":
  x = 998765432
  solution = Solution()
  isPal = solution.isPalindrome(x)

  if isPal:
    print(f"The integer {x} is a palindrome.")
  else:
    print(f"The integer {x} is not a palindrome.")
