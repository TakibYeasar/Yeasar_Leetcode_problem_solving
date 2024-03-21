# Problem Link ====>>https://leetcode.com/problems/plus-one/description/

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)
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
