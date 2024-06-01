
// Problem link ===>> https://leetcode.com/problems/running-sum-of-1d-array/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main()
{
    Solution solution;
    return 0;
}