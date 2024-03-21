
// Problem Link ====>>https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};

int main()
{
    // Create a vector of integers for height
    vector<int> height = {1, 8, 6, 2, 5, 4, 7, 3, 1};

    // Create a Solution object
    Solution solution;

    // Find the maximum area of the histogram
    int max_area = solution.maxArea(height);

    // Print the maximum area value
    cout << "Maximum area of the histogram: " << max_area << endl;

    return 0;
}