// You are given an integer array height of length n.There are n vertical lines drawn such that the two endpoints of the ith
// line are(i, 0) and (i, height[i]).
// Find two lines that together with the x - axis form a container,
// such that the container contains the most water. Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

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