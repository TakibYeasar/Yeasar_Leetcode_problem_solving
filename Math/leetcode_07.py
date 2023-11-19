# Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside
# the signed 32 - bit integer range[-231, 231 - 1], then return 0.Assume the environment does not allow you to store 64 -
# bit integers(signed or unsigned).

class Solution:
  def reverse(self, x: int) -> int:
    """Reverses the given integer.

    Args:
      x: An integer.

    Returns:
      An integer representing the reversed integer.
    """

    rev = 0
    while x != 0:
      rem = x % 10
      rev = rev * 10 + rem
      x //= 10

    # Check if the reversed integer overflows the 32-bit signed integer range.
    if rev > INT_MAX or rev < INT_MIN:
      return 0
    else:
      return rev


def main():
  solution = Solution()

  reversed_integer = solution.reverse(123)  # reversed_integer will be 321

  reversed_integer_2 = solution.reverse(-123)  # reversed_integer_2 will be -321

  print(reversed_integer)
  print(reversed_integer_2)


if __name__ == "__main__":
  main()
