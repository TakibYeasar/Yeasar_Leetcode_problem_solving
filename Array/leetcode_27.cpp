
// Problem Link ====>>https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // Check if the vector is empty.
        if (nums.empty())
        {
            return 0;
        }

        // Iterate over the vector and remove all occurrences of the value `val`.
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[j];
                j--;
            }
            else
            {
                i++;
            }
        }

        // Return the new size of the vector.
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newSize = s.removeElement(nums, val);

    cout << newSize << endl; // prints 2

    return 0;
}