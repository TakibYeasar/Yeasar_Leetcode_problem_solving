
// Problem link ===>> https://leetcode.com/problems/maximum-subarray/description/
// Explaination == = >> https://leetcode.com/problems/maximum-subarray/solutions/1595195/cpython-7-simple-solutions-w-explanation-kb6j/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < size(nums); i++)
        {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }
        return dp[0].back();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        
    }
    return 0;
}