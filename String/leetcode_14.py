# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".

class Solution:
  def longestCommonPrefix(self, strs):
    """
    Finds the longest common prefix of a list of strings.

    Args:
      strs: A list of strings.

    Returns:
      The longest common prefix of the strings in strs, or an empty string if there is no common prefix.
    """

    if not strs:
      return ""

    # Find the shortest string in the list.
    shortest_str = min(strs, key=len)

    # Iterate over the characters of the shortest string and check if they match
    # the corresponding characters of all other strings. If they do, add the character
    # to the prefix. Otherwise, break out of the loop.
    prefix = ""
    for i in range(len(shortest_str)):
      c = shortest_str[i]
      for s in strs:
        if s[i] != c:
          break
      else:
        prefix += c
    return prefix


def main():
  strs = ["flower", "flow", "flight"]
  prefix = Solution().longestCommonPrefix(strs)
  print(prefix)


if __name__ == "__main__":
  main()
