
// Problem link ===>> https://leetcode.com/problems/contiguous-array/description/?envType=problem-list-v2&envId=21r1mgbr

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
    vector<int> prefix;
    int total;
    mt19937 rng;

    Solution(vector<int> &w) : rng(random_device{}())
    {
        total = 0;
        for (int weight : w)
        {
            total += weight;
            prefix.push_back(total);
        }
    }

    int pickIndex()
    {
        uniform_int_distribution<int> dist(1, total);
        int randNum = dist(rng);

        return lower_bound(prefix.begin(), prefix.end(), randNum) - prefix.begin();
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