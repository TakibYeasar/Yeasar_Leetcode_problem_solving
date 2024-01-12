// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
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

int main()
{
    // Create a vector of integers for nums
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    // Create a Solution object
    Solution solution;

    // Find the sum of three integers in nums that is closest to the target
    int closest_sum = solution.threeSumClosest(nums, target);

    // Print the closest sum value
    cout << "Closest sum to " << target << " in nums: " << closest_sum << endl;

    return 0;
}