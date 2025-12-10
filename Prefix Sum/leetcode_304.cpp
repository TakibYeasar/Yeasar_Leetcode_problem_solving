
// Problem link ===>> https://leetcode.com/problems/range-sum-query-2d-immutable/description/?envType=problem-list-v2&envId=21r1mgbr

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

class NumMatrix
{
public:
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        if (n == 0)
            return;

        prefixSum.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefixSum[i + 1][j + 1] =
                    prefixSum[i][j + 1] +
                    prefixSum[i + 1][j] -
                    prefixSum[i][j] +
                    matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefixSum[row2 + 1][col2 + 1] - prefixSum[row2 + 1][col1] - prefixSum[row1][col2 + 1] + prefixSum[row1][col1];
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