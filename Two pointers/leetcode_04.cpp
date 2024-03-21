
// Problem Link ====>> https://leetcode.com/problems/median-of-two-sorted-arrays/description/

//===================>>> Approach 2 : Two - Pointer Method

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