
// Problem link ===>> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=21r1hia6

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
    vector<int> twoSum_bs(const vector<int> &numbers, int target)
    {
        for (int i = 0; i < (int)numbers.size(); ++i)
        {
            int low = i + 1;
            int high = numbers.size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (numbers[mid] == target - numbers[i])
                {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] > target - numbers[i])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
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