
// Problem link ===>>  https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                long x = grid[i][j];
                x += grid[n - i - 1][j];
                x += grid[n - i - 1][m - j - 1];
                x += grid[i][m - j - 1];
                ans += min(x, 4 - x);
            }
        }
        int c = 0;
        int cnt = 0;
        if (n % 2 == 1)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (grid[n / 2][j] != grid[n / 2][m - j - 1])
                {
                    ans++;
                    cnt++;
                }
                if ((grid[n / 2][j] == grid[n / 2][m - j - 1]) && grid[n / 2][j] == 1)
                {
                    c++;
                }
            }
        }
        if (m % 2 == 1)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (grid[j][m / 2] != grid[n - j - 1][m / 2])
                {
                    ans++;
                    cnt++;
                }
                if ((grid[j][m / 2] == grid[n - j - 1][m / 2]) && grid[j][m / 2] == 1)
                {
                    c++;
                }
            }
        }
        if ((c % 2 == 1) && (cnt == 0))
            ans += 2;
        if ((n % 2 == 1) && (m % 2 == 1) && (grid[n / 2][m / 2] == 1))
            ans++;
        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution sol;
        cout << sol.minFlips(grid) << endl;
    }
    return 0;
}