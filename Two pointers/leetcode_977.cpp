
// Problem link ===>> https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        vector<int> v;
        while (1)
        {
            if (nums[l] * nums[l] > nums[r] * nums[r])
            {
                v.push_back(nums[l] * nums[l]);
                l++;
            }
            else
            {
                v.push_back(nums[r] * nums[r]);
                r--;
            }

            if (l == r)
            {
                v.push_back(nums[l] * nums[l]);
                break;
            }

            reverse(v.begin(), v.end());

            for (int x : v)
            {
                cout << x << " ";
            }
            cout << endl;
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