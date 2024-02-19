// There is an integer array nums sorted in ascending order(with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length)
// such that the resulting array is[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](0 - indexed).
// For example, [ 0, 1, 2, 4, 5, 6, 7 ] might be rotated at pivot index 3 and become[4, 5, 6, 7, 0, 1, 2].
// Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    int target;
    vector<int> nums;

    cout << "Enter the target: ";
    cin >> target;

    cout << "Enter the array elements (separated by spaces): ";
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    Solution solution;
    int result = solution.search(nums, target);

    if (result == -1)
    {
        cout << "Target " << target << " not found in the array." << endl;
    }
    else
    {
        cout << "Target " << target << " found at index: " << result << endl;
    }

    return 0;
}
