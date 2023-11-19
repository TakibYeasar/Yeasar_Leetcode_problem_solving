// Given a sorted array of distinct integers and a target value, return the index if the target is found.If not, 
// return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>
    using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // Check if the vector is empty.
        if (nums.empty())
        {
            return 0;
        }

        // Iterate over the vector and find the first element that is greater than or equal to the target.
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
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

        // If the target is not found, return the index where it would be inserted.
        return left;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = s.searchInsert(nums, target);

    cout << index << endl; // prints 2

    return 0;
}