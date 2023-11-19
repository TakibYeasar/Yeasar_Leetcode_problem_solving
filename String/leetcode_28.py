# Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Returns the index of the first occurrence of the needle string in the haystack string.

        Args:
            haystack: The haystack string.
            needle: The needle string.

        Returns:
            The index of the first occurrence of the needle string in the haystack string, or -1 if the needle string is not found.
        """

        # Check if the needle string is empty.
        if needle == "":
            return 0

        # Iterate over the haystack string and compare each substring of length `needle.length()` to the needle string.
        # If a match is found, the index of the match is returned. Otherwise, -1 is returned.
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i

        return -1

solution = Solution()
haystack = "Hello, world!"
needle = "world"
index = solution.strStr(haystack, needle)

print(index)  # prints 7
