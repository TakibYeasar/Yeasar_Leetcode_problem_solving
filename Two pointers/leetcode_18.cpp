
// Problem Link ====>>https://leetcode.com/problems/4sum/description/

// ===================>>>✔️ Solution 2 : Sort then Two Pointers

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int l = j + 1, r = n - 1;
                long long remain = (long long)(target) - (long long)nums[i] - (long long)nums[j];
                while (l < r)
                {
                    if ((long long)(nums[l] + nums[r]) == remain)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l - 1] == nums[l])
                            ++l; // Skip duplicate nums[l]
                    }
                    else if ((long long)(nums[l] + nums[r]) > remain)
                    {
                        --r;
                    }
                    else
                    {
                        ++l;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    ++j; // Skip duplicate nums[j]
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i; // Skip duplicate nums[i]
        }
        return ans;
    }
};

int main()
{
    // Create a vector of integers for nums
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Create a Solution object
    Solution solution;

    // Find all unique quadruplets in the array that sum to zero
    vector<vector<int>> quadruplets = solution.fourSum(nums, target);

    // Print the unique quadruplets
    for (const vector<int> &quadruplet : quadruplets)
    {
        for (const int &num : quadruplet)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}