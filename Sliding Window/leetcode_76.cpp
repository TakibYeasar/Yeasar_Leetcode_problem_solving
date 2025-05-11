
// Problem link ===>> https://leetcode.com/problems/minimum-window-substring/description/?envType=problem-list-v2&envId=21r1z5od

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld = long double
#define endl '\n'
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        vector<ll> map(128, 0);
        ll cnt = t.length();
        ll start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        for (char c : t)
            map[c]++;

        while (end < s.length())
        {
            if (map[s[end++]]-- > 0)
                cnt--;

            while (cnt == 0)
            {
                if (end - start < minLen)
                {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start]]++ == 0)
                    cnt++;
            }
        }
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