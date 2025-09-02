
// Problem link ===>> https://leetcode.com/problems/valid-number/description/?envType=problem-list-v2&envId=21r4yhih

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
    bool isNumber(string S)
    {
        bool num = false, exp = false, sign = false, dec = false;
        for (auto c : S)
            if (c >= '0' && c <= '9')
                num = true;
            else if (c == 'e' || c == 'E')
                if (exp || !num)
                    return false;
                else
                    exp = true, sign = false, num = false, dec = false;
            else if (c == '+' || c == '-')
                if (sign || num || dec)
                    return false;
                else
                    sign = true;
            else if (c == '.')
                if (dec || exp)
                    return false;
                else
                    dec = true;
            else
                return false;
        return num;
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