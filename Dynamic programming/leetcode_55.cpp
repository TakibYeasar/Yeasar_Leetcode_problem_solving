
// Problem link ===>> https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int gas = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (gas < i)
                return false;
            gas = max(gas, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << solution.canJump(nums1) << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums2) << endl;

    return 0;
}