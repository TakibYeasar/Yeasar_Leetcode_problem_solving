
// Problem link ===>> https://leetcode.com/problems/continuous-subarray-sum/description/?envType=problem-list-v2&envId=21r1mgbr

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
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> modMap;
        modMap[0] = -1;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int mod = prefixSum % k;

            if (modMap.find(mod) != modMap.end())
            {
                if (i - modMap[mod] > 1)
                {
                    return true;
                }
            }
            else
            {
                modMap[mod] = i;
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