# Problem Link ====>>https://leetcode.com/problems/divide-two-integers/description/

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
