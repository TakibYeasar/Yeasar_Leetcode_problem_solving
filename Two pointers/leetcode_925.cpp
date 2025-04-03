
// Problem link ===>> https://leetcode.com/problems/long-pressed-name/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int n = name.size();
        int t = typed.size();
        int p1 = 0, p2 = 0;
        while (1)
        {
            if (p1 >= n && p2 >= t)
            {
                return true;
            }

            if (p1 >= n)
            {
                if (typed[p2] == name.back())
                {
                    p2++;
                    continue;
                }
                else
                {
                    return false;
                }
            }

            if (p2 >= n)
            {
                return false;
            }

            if (name[p1] == typed[p2])
            {
                p1++;
                p2++;
            }
            else
            {
                if (p1 == 0)
                {
                    return false;
                }
                else if (name[p1 - 1] == typed[p2])
                {
                    p2++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
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