# Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
# The integer division should truncate toward zero, which means losing its fractional part.For example, 
# 8.345 would be truncated to 8, and-2.7335 would be truncated to - 2.
# Return the quotient after dividing dividend by divisor.
# Note : Assume we are dealing with an environment that could only store integers within the 32-bit signed integer
#  range : [−231, 231 − 1 ].For this problem,if the quotient is strictly greater than 231 - 1, then return 231 - 1, 
#  and if the quotient is strictly less than - 231, then return -231.

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if divisor == 0 or (dividend == INT_MIN and divisor == -1):
            return INT_MAX if divisor != -1 else INT_MIN

        sign = (dividend < 0) ^ (divisor < 0)
        dvd = abs(dividend)
        dvs = abs(divisor)
        quotient = 0

        while dvd >= dvs:
            temp = dvs
            multiple = 1
            while dvd >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            dvd -= temp
            quotient += multiple

        return quotient if not sign else -quotient


# Test the Solution class
sol = Solution()
dividend = 10
divisor = 3
result = sol.divide(dividend, divisor)
print("Result of dividing", dividend, "by", divisor, "is:", result)
