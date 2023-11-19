// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log(m + n)).

// Problem Understanding : In simpler terms, you need to find the middle value of the combined, sorted array formed by
// merging nums1 and nums2.If the combined array has an even number of elements, you should return the average of the two
// middle values.If it has an odd number of elements, you should return the middle value itself.



//===================>>> Approach 3 : Binary Search
// Use binary search to partition the smaller of the two input arrays into two parts.
// Find the partition of the larger array such that the sum of elements on the left side of the partition in both arrays
// is half of the total elements.
// Check if this partition is valid by verifying if the largest number on the left side is
// smaller than the smallest number on the right side.If the partition is valid,
// calculate and return the median.

// Time Complexity
// O(logm / logn)

// Space Complexity
// O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1;       // Calculate mid index for nums2

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2)
            {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else
            {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }

        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};
