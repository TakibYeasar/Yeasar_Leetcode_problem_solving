
// Problem Link ====>>https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

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