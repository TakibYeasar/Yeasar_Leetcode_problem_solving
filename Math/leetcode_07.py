# Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside
# the signed 32 - bit integer range[-231, 231 - 1], then return 0.Assume the environment does not allow you to store 64 -
# bit integers(signed or unsigned).

import sys


class Solution:
    def reverse(self, x: int) -> int:
        reversed_number = 0
        while x != 0:
            remainder = x % 10
            reversed_number = reversed_number * 10 + remainder
            x //= 10

        if reversed_number > sys.maxint or reversed_number < -sys.maxint - 1:
            return 0
        else:
            return reversed_number


if __name__ == "__main__":
    x = -12345
    solution = Solution()
    reversed_integer = solution.reverse(x)

    if reversed_integer == 0:
        print("The reversed integer overflows the 32-bit signed integer range.")
    else:
        print(f"The reversed integer of {x} is: {reversed_integer}")
