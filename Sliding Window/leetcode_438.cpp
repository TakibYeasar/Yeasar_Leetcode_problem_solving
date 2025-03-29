
// Problem link ===>> https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> cnt_p(26, 0);
        vector<int> cnt_w(26, 0);

        for (char c : p)
        {
            cnt_p[c - 'a']++;
        }

        int k = p.size();
        int n = s.size();
        for (int i = 0; i < k; i++)
        {
            cnt_w[s[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            bool matched = true;
            for (int j = 0; j < 26; j++)
            {
                if (cnt_p[j] != cnt_w[j])
                {
                    matched = false;
                    break;
                }
            }

            if (matched)
            {
                cout << i << " ";
            }

            cnt_w[s[i] - 'a']--;
            if (i + k >= n)
            {
                break;
            }
            cnt_w[s[i + k] - 'a']--;
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    return 0;
}