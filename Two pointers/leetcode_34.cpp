// Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array,return [ -1, -1 ].
// You must write an algorithm with O(log n) runtime complexity.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target)
                {
                    first--;
                }
                while (last < nums.size() - 1 && nums[last + 1] == target)
                {
                    last++;
                }
                break;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return {first, last};
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
    vector<int> result = solution.searchRange(nums, target);

    if (result[0] == -1)
    {
        cout << "Target " << target << " not found in the array." << endl;
    }
    else
    {
        cout << "Target " << target << " found at positions: " << result[0] << " and " << result[1] << endl;
    }

    return 0;
}
