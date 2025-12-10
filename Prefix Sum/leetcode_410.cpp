
// Problem link ===>> https://leetcode.com/problems/split-array-largest-sum/description/?envType=problem-list-v2&envId=21r1mgbr

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
    bool helper(vector<int> &nums, int perK, int k)
    {
        int count = 1;
        long long sum = 0;

        for (int num : nums)
        {
            if (sum + num > perK)
            {
                count++;
                sum = num;
            }
            else
            {
                sum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        int soln = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (helper(nums, mid, k))
            {
                soln = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return soln;
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