
// Problem link ===>> https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=21r1dm61

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
template <typename K, typename V>
using ordered_map = tree<
    K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        function<bool(int, int, int)> dfs = [&](int r, int c, int index) {
            if (index == word.size()) return true;
            if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || board[r][c] != word[index]) {
                return false;
            }

            visited[r][c] = true;
            bool found = dfs(r + 1, c, index + 1) ||
                         dfs(r - 1, c, index + 1) ||
                         dfs(r, c + 1, index + 1) ||
                         dfs(r, c - 1, index + 1);
            visited[r][c] = false; // backtrack
            return found;
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0] && dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
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