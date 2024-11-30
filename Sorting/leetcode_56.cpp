
// Problem link ===>>  https://leetcode.com/problems/merge-intervals/description/
// submission link ===>>

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1])
            {
                prev[1] = max(prev[1], interval[1]);
            }
            else
            {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;
    };
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