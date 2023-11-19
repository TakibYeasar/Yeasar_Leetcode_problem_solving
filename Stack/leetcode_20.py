# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
# An input string is valid if : Open brackets must be closed by the same type of brackets.Open brackets must
# be closed in the correct order.Every close bracket has a corresponding open bracket of the same type.

class Solution:
    def isValid(self, s: str) -> bool:
        """
        Checks if a string contains valid parentheses.

        Args:
            s: A string.

        Returns:
            True if the string contains valid parentheses, False otherwise.
        """

        stack = []
        for c in s:
            if c in "([{":
                stack.append(c)
            elif c in ")]}":
                if not stack or stack.pop() != c:
                    return False

        return len(stack) == 0
