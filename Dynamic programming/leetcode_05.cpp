
// Problem Link ====>> https://leetcode.com/problems/longest-palindromic-substring/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2])
                {
                    dp[i][i + len - 1] = true;
                    if (len > maxLen)
                    {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    string s = "babad";
    Solution solution;
    string result = solution.longestPalindrome(s);
    cout << result << endl;

    return 0;
}


