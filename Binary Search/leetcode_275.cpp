
// Problem link ===>> https://leetcode.com/problems/h-index-ii/description/?envType=problem-list-v2&envId=21r1hia6

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
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int h = n - mid;

            if (citations[mid] >= h)
            {
                ans = h;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
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