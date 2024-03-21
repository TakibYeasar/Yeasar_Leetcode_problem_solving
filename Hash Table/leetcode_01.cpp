
// Problem Link ====>> https://leetcode.com/problems/two-sum/description/

// ===================>>> Solution 2 : (Hash Table)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++)
        {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i)
            {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

int main()
{
    // Create vector of integers for nums
    vector<int> nums = {2, 7, 11, 15};

    // Target value
    int target = 9;

    // Create a Solution object
    Solution solution;

    // Find the pair of indices that sum up to target
    vector<int> indices = solution.twoSum(nums, target);

    // Check if a solution was found
    if (indices.empty())
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Indices of the two numbers that sum up to target: " << indices[0] << ", " << indices[1] << endl;
    }

    return 0;
}

// ===================>>> Solution 3: (One-pass Hash Table)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement))
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

int main()
{
    // Create vector of integers for nums
    vector<int> nums = {2, 7, 11, 15};

    // Target value
    int target = 9;

    // Create a Solution object
    Solution solution;

    // Find the pair of indices that sum up to target
    vector<int> indices = solution.twoSum(nums, target);

    // Check if a solution was found
    if (indices.empty())
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Indices of the two numbers that sum up to target: " << indices[0] << ", " << indices[1] << endl;
    }

    return 0;
}