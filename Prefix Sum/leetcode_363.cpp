
// Problem link ===>> https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/?envType=problem-list-v2&envId=21r1mgbr

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
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int r1 = 0; r1 < m; r1++)
        {
            vector<int> arr(n, 0);

            for (int r2 = r1; r2 < m; r2++)
            {
                for (int c = 0; c < n; c++)
                    arr[c] += matrix[r2][c];

                ans = max(ans, maxSumSubArray(arr, k));
            }
        }

        return ans;
    }

private:
    int maxSumSubArray(vector<int> &arr, int k)
    {
        set<int> seen;
        seen.insert(0);
        int right = 0;
        int ans = INT_MIN;

        for (int x : arr)
        {
            right += x;

            auto it = seen.lower_bound(right - k);
            if (it != seen.end())
            {
                ans = max(ans, right - *it);
            }

            seen.insert(right);
        }

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