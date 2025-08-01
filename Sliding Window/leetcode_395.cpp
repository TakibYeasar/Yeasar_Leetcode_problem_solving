
// Problem link ===>> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/?envType=problem-list-v2&envId=21r1z5od

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
template <typename T>
using ordered_set_mul = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
private:
    int getUniqueCharCount(const string &s)
    {
        vector<bool> seen(26, false);
        int unique = 0;

        for (char ch : s)
        {
            int idx = ch - 'a';
            if (!seen[idx])
            {
                seen[idx] = true;
                unique++;
            }
        }

        return unique;
    };

public:
    int longestSubstring(string s, int k)
    {
        int maxUnique = getUniqueCharCount(s);
        int result = 0;

        for (int targetUnique = 1; targetUnique <= maxUnique; ++targetUnique)
        {
            vector<int> freq(26, 0);
            int start = 0, end = 0;
            int unique = 0, countAtLeastK = 0;

            while (end < s.size())
            {
                if (unique <= targetUnique)
                {
                    int idx = s[end] - 'a';
                    if (freq[idx] == 0)
                        unique++;
                    freq[idx]++;
                    if (freq[idx] == k)
                        countAtLeastK++;
                    end++;
                }
                else
                {
                    int idx = s[start] - 'a';
                    if (freq[idx] == k)
                        countAtLeastK--;
                    freq[idx]--;
                    if (freq[idx] == 0)
                        unique--;
                    start++;
                }
                if (unique == targetUnique && unique == countAtLeastK)
                {
                    result = max(result, end - start);
                }
            }
        }
        return result;
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