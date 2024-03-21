
// Problem Link ====>>https://leetcode.com/problems/trapping-rain-water/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int trapped_water = 0;

        while (left < right)
        {
            // Update the maximum heights from left and right
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            // Calculate trapped water for the current position
            if (left_max < right_max)
            {
                trapped_water += left_max - height[left];
                left++;
            }
            else
            {
                trapped_water += right_max - height[right];
                right--;
            }
        }

        return trapped_water;
    }
};

int main()
{
    vector<int> elevation_map = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int trapped_water = sol.trap(elevation_map);

    cout << "Trapped water: " << trapped_water << " units" << endl;
    return 0;
}
