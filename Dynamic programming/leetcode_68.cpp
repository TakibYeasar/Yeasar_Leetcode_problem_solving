
// Problem link ===>> https://leetcode.com/problems/text-justification/description/?envType=problem-list-v2&envId=21r4yhih

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
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        vector<string> cur;
        int num_of_letters = 0;

        for (string word : words)
        {
            if (word.size() + cur.size() + num_of_letters > maxWidth)
            {
                for (int i = 0; i < maxWidth - num_of_letters; i++)
                {
                    cur[i % (cur.size() - 1 ? cur.size() - 1 : 1)] += ' ';
                }
                res.push_back("");
                for (string s : cur)
                    res.back() += s;
                cur.clear();
                num_of_letters = 0;
            }
            cur.push_back(word);
            num_of_letters += word.size();
        }

        string last_line = "";
        for (string s : cur)
            last_line += s + ' ';
        last_line = last_line.substr(0, last_line.size() - 1); // remove trailing space
        while (last_line.size() < maxWidth)
            last_line += ' ';
        res.push_back(last_line);

        return res;
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