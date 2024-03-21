
# Problem Link ====>> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

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
def lengthOfLongestSubstring(s):
    charSet = set()
    maxLength = 0
    left = 0

    for right in range(len(s)):
        if s[right] not in charSet:
            charSet.add(s[right])
            maxLength = max(maxLength, right - left + 1)
        else:
            while s[right] in charSet:
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])

    return maxLength

if __name__ == "__main__":
    s = "abcabcbb"
    maxLength = lengthOfLongestSubstring(s)

    print("The length of the longest substring without repeating characters in", s, "is:", maxLength)


# //= == == == == == == == == == >> > Approach 2 - Unordered Map
def lengthOfLongestSubstring(s):
    char_map = {}
    max_length = 0
    left = 0

    for right in range(len(s)):
        if s[right] not in char_map or char_map[s[right]] < left:
            char_map[s[right]] = right
            max_length = max(max_length, right - left + 1)
        else:
            left = char_map[s[right]] + 1
            char_map[s[right]] = right

    return max_length

if __name__ == "__main__":
    s = "abcabcbb"
    max_length = lengthOfLongestSubstring(s)

    print(f"The length of the longest substring without repeating characters in {s} is: {max_length}")


# //===================>>> Approach 3 - Integer Array
def lengthOfLongestSubstring(s):
    char_index = [None] * 128
    max_length = 0
    left = 0

    for right in range(len(s)):
        if char_index[ord(s[right])] is not None and char_index[ord(s[right])] >= left:
            left = char_index[ord(s[right])] + 1

        char_index[ord(s[right])] = right
        max_length = max(max_length, right - left + 1)

    return max_length


if __name__ == "__main__":
    s = "abcabcbb"
    max_length = lengthOfLongestSubstring(s)

    print("The length of the longest substring without repeating characters in",
          s, "is:", max_length)
