// Given an array nums of n integers, return an array of all the unique quadruplets[nums[a], nums[b], nums[c], nums[d]]
// such that : 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// ===================>>>✔️ Solution 1 : HashSet
// The idea is to use HashSet to track past elements.
// We iterate the combinations of nums[i], nums[j], nums[k], and calculate the last number by lastNumber = target - nums[i] - nums[j] - nums[k].
// We check if lastNumber is existed the past by checking in the HashSet, if existed, then it form a quadruplets then add it to the answer.

// Complexity :
// Time : O(N ^ 3)
// Extra Space(Without count output as space) : O(N)

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
        unordered_set<int> seen;
        set<multiset<int>> ans_set;
        int n = size(nums);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int lastNumber = target - (nums[i] + nums[j] + nums[k]);

                    if (seen.count(lastNumber))
                    {
                        ans_set.emplace(multiset<int>{nums[i], nums[j], nums[k], lastNumber});
                    }
                }
            }
            seen.insert(nums[i]);
        }
        vector<vector<int>> ans(size(ans_set));
        for_each(begin(ans_set), end(ans_set), [&, i(0)](auto &el) mutable
                 { ans[i++] = vector<int>(begin(el), end(el)); });
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;
    vector<vector<int>> quadruplets = solution.fourSum(nums, target);

    for (const vector<int> &quadruplet : quadruplets)
    {
        for (const int &num : quadruplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}