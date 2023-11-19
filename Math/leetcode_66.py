# You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
# The digits are ordered from most significant to least significant in left - to - right order.The large integer does
# not contain any leading 0's. return the resulting array of digits.

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Adds one to a list of digits.

        Args:
            digits: A list of digits.

        Returns:
            A list of digits representing the sum of the input digits and one.
        """

        carry = 1
        for i in reversed(range(len(digits))):
            sum = digits[i] + carry
            digits[i] = sum % 10
            carry = sum // 10

        if carry == 1:
            digits.insert(0, 1)

        return digits

solution = Solution()
digits = [1, 2, 3]
result = solution.plusOne(digits)

print(result)  # prints [2, 3, 4]
