# Given a string containing just the characters '(' and ')', return the length of the longest valid(well - formed) parentheses substring.

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Initialize the stack with -1 to handle edge cases
        max_len = 0

        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)  # Push the index of '(' onto the stack
            else:
                stack.pop()  # Pop the '(' index from the stack

                if not stack:
                    # If the stack is empty, push the current index
                    stack.append(i)
                else:
                    # Calculate the length of valid parentheses
                    max_len = max(max_len, i - stack[-1])

        return max_len


# Test the Solution class
sol = Solution()
input_str = "(()))())("  # Example input
result = sol.longestValidParentheses(input_str)
print("Length of the longest valid parentheses:", result)
