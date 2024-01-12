// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log(m + n)).

// Problem Understanding : In simpler terms, you need to find the middle value of the combined, sorted array formed by
// merging nums1 and nums2.If the combined array has an even number of elements, you should return the average of the two
// middle values.If it has an odd number of elements, you should return the middle value itself.

//===================>>> Approach 2 : Two - Pointer Method
// Initialize two pointers,i and j, both initially set to 0.
// Move the pointer that corresponds to the smaller value forward at each step.
// Continue moving the pointers until you have processed half of the total number of elements.
// Calculate and return the median based on the values pointed to by i and j.

// Time Complexity
// where ‘n’ & ‘m’ are the sizes of the two arrays.

// Space Complexity
//  O(1).
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;

        // Find median.
        for (int count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;
            if (i != n && j != m)
            {
                if (nums1[i] > nums2[j])
                {
                    m1 = nums2[j++];
                }
                else
                {
                    m1 = nums1[i++];
                }
            }
            else if (i < n)
            {
                m1 = nums1[i++];
            }
            else
            {
                m1 = nums2[j++];
            }
        }

        // Check if the sum of n and m is odd.
        if ((n + m) % 2 == 1)
        {
            return static_cast<double>(m1);
        }
        else
        {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
    }
};

int main()
{
    // Create vectors of integers for nums1 and nums2
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Create a Solution object
    Solution solution;

    // Find the median of the two sorted arrays
    double median = solution.findMedianSortedArrays(nums1, nums2);

    // Print the median value
    cout << "Median of the two sorted arrays: " << median << endl;

    return 0;
}