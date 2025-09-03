
// Problem link ===>> https://leetcode.com/problems/ugly-number-iii/description/?envType=problem-list-v2&envId=21r1b7y6

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
    int nthUglyNumber(int n, int a, int b, int c)
    {
        auto gcd = [](ll x, ll y) {
            while (y) {
                x %= y;
                swap(x, y);
            }
            return x;
        };

        auto lcm = [&](ll x, ll y) {
            return (x / gcd(x, y)) * y;
        };

        ll ab = lcm(a, b);
        ll ac = lcm(a, c);
        ll bc = lcm(b, c);
        ll abc = lcm(ab, c);

        auto count = [&](ll x) {
            return (x / a) + (x / b) + (x / c) - (x / ab) - (x / ac) - (x / bc) + (x / abc);
        };

        ll left = 1, right = 2e9;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (count(mid) >= n)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
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