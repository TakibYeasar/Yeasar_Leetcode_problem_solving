
# Problem link ===>>  https://leetcode.com/problems/multiply-strings/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        len1, len2 = len(num1), len(num2)
        result = [0] * (len1 + len2)

        for i in range(len1 - 1, -1, -1):
            for j in range(len2 - 1, -1, -1):
                # Product of current digits
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                p1 = i + j  # Carry position
                p2 = i + j + 1  # Remainder position

                sum_carry = mul + result[p2]

                result[p2] = sum_carry % 10  # Store remainder
                result[p1] += sum_carry // 10  # Add carry to the next position

        # Convert result array to string, removing leading zeros
        result_str = ''.join(map(str, result)).lstrip('0')

        return result_str if result_str else "0"


# For testing multiple test cases
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        num1 = input().strip()
        num2 = input().strip()

        s = Solution()
        result = s.multiply(num1, num2)
        print(result)
