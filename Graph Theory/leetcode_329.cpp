
// Problem link ===>> https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/?envType=problem-list-v2&envId=21rco0xh

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define endl '\n'
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_mul = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        function<int(int, int, int)> dfs = [&](int i, int j, int prev)
        {
            if (i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= prev)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];

            int left = dfs(i, j - 1, matrix[i][j]);
            int right = dfs(i, j + 1, matrix[i][j]);
            int up = dfs(i - 1, j, matrix[i][j]);
            int down = dfs(i + 1, j, matrix[i][j]);

            dp[i][j] = 1 + max({left, right, up, down});
            return dp[i][j];
        };

        int ans = -1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, dfs(i, j, -1));

        return ans;
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