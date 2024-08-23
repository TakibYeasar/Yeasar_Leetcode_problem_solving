
// Problem link ===>> https://leetcode.com/problems/find-the-number-of-winning-players/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        int ans = 0;
        for (int i = 0; i < n; i++){
            map<int, int> mp;
            for (int j = 0; j < pick.size(); j++)
            {
                if(pick[j][0]==i){
                    mp[pick[j][1]]++;
                    if (mp[pick[j][1]]>i){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> pick(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            cin >> pick[i][0] >> pick[i][1];
        }
        Solution sol;
        cout << sol.winningPlayerCount(n, pick) << endl;
    }
    return 0;
}