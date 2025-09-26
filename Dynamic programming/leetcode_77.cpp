
// Problem link ===>> https://leetcode.com/problems/combinations/?envType=problem-list-v2&envId=21r4yhih

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
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> backtrack = [&](int start, int k)
        {
            if (k == 0)
            {
                ans.push_back(temp);
                return;
            }
            for (int i = start; i <= n; i++)
            {
                temp.push_back(i);
                backtrack(i + 1, k - 1);
                temp.pop_back();
            }
        };
        backtrack(1, k);
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