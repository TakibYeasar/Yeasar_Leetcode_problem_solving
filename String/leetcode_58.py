# Problem Link ====>>https://leetcode.com/problems/length-of-last-word/description/

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        """
        Returns the length of the last word in a string.

        Args:
            s: The string to find the length of the last word in.

        Returns:
            The length of the last word in `s`.
        """

        # Remove any trailing whitespace.
        s = s.strip()

        # Iterate over the string from the back to the front, counting the number of characters in the last word.
        len = 0
        for i in reversed(range(len(s))):
            if s[i] == " ":
                break
            len += 1

        return len

solution = Solution()
s = "Hello World"
len = solution.lengthOfLastWord(s)
print(len)  # prints 5
