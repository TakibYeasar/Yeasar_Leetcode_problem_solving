
# Problem Link ====>> https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution:
    def myAtoi(self, str: str) -> int:
        result = 0
        sign = 1
        i = 0
        n = len(str)

        # Skip leading whitespace
        while i < n and str[i] == ' ':
            i += 1

        # Handle the sign
        if i < n and (str[i] == '+' or str[i] == '-'):
            sign = 1 if str[i] == '+' else -1
            i += 1

        # Convert the digits to an integer
        while i < n and str[i].isdigit():
            digit = int(str[i])

            # Check for overflow
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7):
                return INT_MAX if sign == 1 else INT_MIN

            result = result * 10 + digit
            i += 1

        return result * sign


if __name__ == "__main__":
    str = "12345"

    solution = Solution()
    result = solution.myAtoi(str)

    print(f"The integer value of '{str}' is: {result}")


