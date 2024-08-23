
// Problem link ===>>  https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        ll rows = 0;
        ll cols = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m/2; j++){
                if (grid[i][j] != grid[i][m-j-1]){
                    rows++;
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n / 2; j++){
                if (grid[j][i] != grid[n - j - 1][i])
                {
                    cols++;
                }
            }
        }

        return min(rows, cols);
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