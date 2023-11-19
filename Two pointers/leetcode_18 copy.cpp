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

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int k = j + 1; k < n;k++){
                    int lastNumber = target - (nums[i] + nums[j] + nums[k]);

                    if(seen.count(lastNumber)){
                        ans_set.emplace(multiset<int>{nums[i], nums[j], nums[k], lastNumber});
                    }
                }
            }
            seen.insert(nums[i]);
        }
        vector<vector<int>> ans(size(ans_set));
        for_each(begin(ans_set), end(ans_set), [&, i(0)](auto &el) mutable { ans[i++] = vector<int>(begin(el), end(el)); });
        return ans;
    }
};

// ===================>>>✔️ Solution 2 : Sort then Two Pointers

// Sort nums in increasing order.
// We fix nums[i], nums[j] by iterating the combination of nums[i], nums[j], then the problem now become to very classic problem 1. Two Sum.
// By using two pointers, one points to left, the other points to right, remain = target - nums[i] - nums[j].
// If: nums[left] + nums[right] == remain 
// Found a valid quadruplets 
// Else: if nums[left] + nums[right] > remain 
// Sum is bigger than remain, need to decrease sum by right -= 1 
// Else : Increasing sum by left += 1.

// Complexity :
// Time : O(N ^ 3)
// Extra Space(Without count output as space) : O(sorting)

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
