
// Problem link ===>>  https://leetcode.com/problems/wildcard-matching/description/
// submission link ===>>

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 0; j < m && p[j] == '*'; ++j)
        {
            dp[0][j + 1] = true;
        }

        for(int i =1; i<= m; ++i){
            for(int j=1; j<=n; ++j){
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string s = "aa";
    string p = "*";

    Solution solution;
    bool match = solution.isMatch(s, p);

    if (match)
    {
        cout << "The pattern matches the string." << endl;
    }
    else
    {
        cout << "The pattern does not match the string." << endl;
    }

    return 0;
}