// Given an integer array nums sorted in non - decreasing order, remove the duplicates in - place such that each
// unique element appears only once.The relative order of the elements should be kept the same.Then return the number
// of unique elements in nums.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int>nums;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    int k = s.removeDuplicates(nums);

    cout << k << endl;

    return 0;
}