
// Problem Link ====>> https://leetcode.com/problems/median-of-two-sorted-arrays/description/

//===================>>> Approach 1 : Merge and Sort

#include <iostream>
#include <vector>
#include <algorithm>
        using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Get the sizes of both input arrays.
        int n = nums1.size();
        int m = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> merged;
        for (int i = 0; i < n; i++)
        {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            merged.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        // Calculate the total number of elements in the merged array.
        int total = merged.size();

        if (total % 2 == 1)
        {
            // If the total number of elements is odd, return the middle element as the median.
            return static_cast<double>(merged[total / 2]);
        }
        else
        {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
};

int main()
{
    // Create vector of integers for nums1
    vector<int> nums1 = {1, 3, 5};

    // Create vector of integers for nums2
    vector<int> nums2 = {2, 4, 6};

    // Create a Solution object
    Solution solution;

    // Find the median of the two sorted arrays
    double median = solution.findMedianSortedArrays(nums1, nums2);

    // Print the median
    cout << "Median: " << median << endl;

    return 0;
}
