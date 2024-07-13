
// Problem link ===>>  https://leetcode.com/problems/binary-search/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

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

        return -1;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int target;
        cin >> target;

        Solution solution;
        int index = solution.search(nums, target);

        if (index != -1)
        {
            cout << "Target found at index " << index << endl;
        }
        else
        {
            cout << "Target not found" << endl;
        }
    }

    return 0;
}
