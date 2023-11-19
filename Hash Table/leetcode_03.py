# Given a string s, find the length of the longest substring without repeating characters.

class Solution:
  def lengthOfLongestSubstring(self, s):
    max_len = 0
    start = 0
    char_index = {}
    for i in range(len(s)):
      if s[i] in char_index and char_index[s[i]] >= start:
        start = max(char_index[s[i]] + 1, start)
      char_index[s[i]] = i
      max_len = max(max_len, i - start + 1)
    return max_len

def main():
  s = "abcabcbb"
  solution = Solution()
  result = solution.lengthOfLongestSubstring(s)
  print(result)

if __name__ == "__main__":
  main()


# // ===================>>> Approach 1 -
# // Set
  class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      n = len(s)
      maxLength = 0
      charSet = set()
      left = 0

      for right in range(n):
        if s[right] not in charSet:
          charSet.add(s[right])
          maxLength = max(maxLength, right - left + 1)
        else:
          while s[right] in charSet:
            charSet.remove(s[left])
            left += 1
          charSet.add(s[right])

      return maxLength

# //= == == == == == == == == == >> > Approach 2 - Unordered Map
  class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      n = len(s)
      maxLength = 0
      charMap = {}
      left = 0

      for right in range(n):
        if s[right] not in charMap or charMap[s[right]] < left:
          charMap[s[right]] = right
          maxLength = max(maxLength, right - left + 1)
        else:
          left = charMap[s[right]] + 1
          charMap[s[right]] = right

      return maxLength


# //===================>>> Approach 3 - Integer Array

  class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      n = len(s)
      maxLength = 0
      charIndex = [-1] * 128
      left = 0

      for right in range(n):
        if charIndex[ord(s[right])] >= left:
          left = charIndex[ord(s[right])] + 1
        charIndex[ord(s[right])] = right
        maxLength = max(maxLength, right - left + 1)

      return maxLength