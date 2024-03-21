
# Problem Link ====>> https://leetcode.com/problems/regular-expression-matching/description/

def isMatch(s, p):
    m = len(s)
    n = len(p)
    dp = [[False] * (n + 1) for _ in range(m + 1)]

    # Empty string and empty pattern match.
    dp[0][0] = True

    for i in range(m + 1):
        for j in range(1, n + 1):
            if p[j - 1] != '*':
                if i > 0 and (s[i - 1] == p[j - 1] or p[j - 1] == '.'):
                    dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = dp[i][j - 2] or (i > 0 and (s[i - 1] ==
                                            p[j - 2] or p[j - 2] == '.') and dp[i - 1][j])

    return dp[m][n]


s = "aa"
p = "a*"

match = isMatch(s, p)

if match:
    print("The pattern matches the string.")
else:
    print("The pattern does not match the string.")
