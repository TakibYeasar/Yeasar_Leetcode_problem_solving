
// Problem link ===>> https://leetcode.com/problems/spiral-matrix-ii/description/?envType=problem-list-v2&envId=21r4yhih

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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int curr_dir_idx = 0;
        int row = 0, col = 0;

        for (int i = 1; i <= n * n; ++i)
        {
            result[row][col] = i;

            int next_row = row + dirs[curr_dir_idx].first;
            int next_col = col + dirs[curr_dir_idx].second;

            if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || result[next_row][next_col] != 0)
            {
                curr_dir_idx = (curr_dir_idx + 1) % 4;
                next_row = row + dirs[curr_dir_idx].first;
                next_col = col + dirs[curr_dir_idx].second;
            }

            row = next_row;
            col = next_col;
        }

        return result;
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