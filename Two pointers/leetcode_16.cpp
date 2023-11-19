// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size(), sum = 0, ans = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());

        if (n == 3)
            return nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++)
        {
            int first = nums[i];
            int high = i + 1, low = n - 1;
            while (high < low)
            {
                sum = first + nums[high] + nums[low];
                if (sum == target)
                    return target;
                else if (abs(target - sum) < diff)
                {
                    diff = abs(target - sum);
                    ans = sum;
                }
                if (sum > target)
                    low--;
                else
                    high++;
            }
        }
        return ans;
    }
};