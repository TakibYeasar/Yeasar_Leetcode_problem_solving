
// Problem Link ====>>https://leetcode.com/problems/search-in-rotated-sorted-array/description/

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
