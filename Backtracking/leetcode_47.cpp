
// Problem link ===>> https://leetcode.com/problems/permutations-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::set<std::vector<int>> uniquePermutations;
        std::vector<int> currentPermutation;
        std::vector<bool> used(nums.size(), false); // Track used elements

        std::sort(nums.begin(), nums.end()); // Important for handling duplicates

        backtrack(nums, used, currentPermutation, uniquePermutations);

        std::vector<std::vector<int>> result(uniquePermutations.begin(), uniquePermutations.end());
        return result;
    }

private:
    void backtrack(std::vector<int> &nums, std::vector<bool> &used, std::vector<int> &currentPermutation, std::set<std::vector<int>> &uniquePermutations)
    {
        if (currentPermutation.size() == nums.size())
        {
            uniquePermutations.insert(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
                continue; // Skip if already used

            currentPermutation.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, currentPermutation, uniquePermutations);
            used[i] = false;               // Backtrack
            currentPermutation.pop_back(); // Backtrack
        }
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 1, 2};
    std::vector<std::vector<int>> permutations = solution.permuteUnique(nums);

    for (const auto &perm : permutations)
    {
        for (int val : perm)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}