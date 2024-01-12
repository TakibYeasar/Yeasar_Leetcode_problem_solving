# ment the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
#
# The algorithm for myAtoi(string s) is as follows:
#
# Read in and ignore any leading whitespace.
# Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
# Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
# Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
# If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
# Return the integer as the final result.
# Note:
#
# Only the space character ' ' is considered a whitespace character.
# Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
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


