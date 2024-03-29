
// Problem Link ====>>https://leetcode.com/problems/3sum/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 3)
        {
            return result; // Not enough elements to form a triplet
        }

        // Sort the array to make it easier to identify triplets
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    // Create a vector of integers for nums
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Create a Solution object
    Solution solution;

    // Find all unique triplets in the array that sum to zero
    vector<vector<int>> triplets = solution.threeSum(nums);

    // Print the unique triplets
    for (const vector<int> &triplet : triplets)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}