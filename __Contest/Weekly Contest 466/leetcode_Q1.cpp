
// Problem link ===>> https://leetcode.com/contest/weekly-contest-466/problems/minimum-operations-to-equalize-array/description/
// Submission ===>> https://leetcode.com/contest/weekly-contest-466/problems/minimum-operations-to-equalize-array/submissions/1762078214/

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
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        bool allEqual = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[0])
            {
                allEqual = false;
                break;
            }
        }
        if (allEqual)
            return 0;

        return 1;
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