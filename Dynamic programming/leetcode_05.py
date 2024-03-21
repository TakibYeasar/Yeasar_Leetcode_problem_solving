
# Problem Link ====>> https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution:
  def longestPalindrome(self, s):
    n = len(s)
    dp = [[False for j in range(n)] for i in range(n)]
    maxLen = 1
    start = 0
    for i in range(n):
      dp[i][i] = True

    for i in range(n - 1):
      if s[i] == s[i + 1]:
        dp[i][i + 1] = True
        maxLen = 2
        start = i

    for len in range(3, n + 1):
      for i in range(n - len + 1):
        if s[i] == s[i + len - 1] and dp[i + 1][i + len - 2]:
          dp[i][i + len - 1] = True
          if len > maxLen:
            maxLen = len
            start = i

    return s[start: start + maxLen]

def main():
  s = "babad"
  solution = Solution()
  result = solution.longestPalindrome(s)
  print(result)

if __name__ == "__main__":
  main()
