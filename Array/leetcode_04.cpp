// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log(m + n)).

// Problem Understanding : In simpler terms, you need to find the middle value of the combined, sorted array formed by
// merging nums1 and nums2.If the combined array has an even number of elements, you should return the average of the two
// middle values.If it has an odd number of elements, you should return the middle value itself.

//===================>>> Approach 1 : Merge and Sort
// Create a new array with a size equal to the total number of elements in both input arrays.
// Insert elements from both input arrays into the new array.
// Sort the new array.Find and return the median of the sorted array.

// Time Complexity
// In the worst case TC is O((n + m) * log(n + m)) .

// Space Complexity
// O(n + m), where ‘n’ and ‘m’ are the sizes of the arrays.

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
