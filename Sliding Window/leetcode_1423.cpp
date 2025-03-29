
// Problem link ===>>  https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution
{
public:
    int maxScore(vector<int> &C, int K)
    {
        int total = 0;
        for (int i = 0; i < K; i++)
        {
            total += C[i];
        }
        int best = total;
        for (int i = K - 1, j = C.size() - 1; ~i, i--, j--;)
        {
            total += C[j] - C[i];
            best = max(best, total);
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