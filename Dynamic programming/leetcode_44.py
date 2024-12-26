
# Problem link ===>>  https://leetcode.com/problems/wildcard-matching/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        
        dp[0][0] = True
        
        for j in range(n):
            if p[j] == '*':
                dp[0][j+1] = dp[0][j]
            else:
                break
        
        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
                else:
                    dp[i][j] = (s[i - 1] == p[j - 1] or p[j - 1]
                                == '?') and dp[i - 1][j - 1]

        return dp[m][n]


if __name__ == "__main__":
    solution = Solution()
    print(solution.isMatch("aa", "a*"))
