# Problem Link ====>>https://leetcode.com/problems/add-binary/description/

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        Adds two binary strings.

        Args:
            a: The first binary string.
            b: The second binary string.

        Returns:
            The sum of `a` and `b` in binary.
        """

        result = ""
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        while i >= 0 or j >= 0:
            sum = carry
            if i >= 0:
                sum += int(a[i])
            if j >= 0:
                sum += int(b[j])
            carry = sum // 2
            result = str(sum % 2) + result
            i -= 1
            j -= 1

        if carry == 1:
            result = "1" + result

        return result

solution = Solution()
result = solution.addBinary("11", "1")
print(result)  # prints 100
