# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log(m + n)).

# //===================>>> Approach 1 : Merge and Sort
class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Merge the two sorted arrays into a single sorted array
        merged_nums = nums1 + nums2
        merged_nums.sort()

        # Get the length of the merged array
        n = len(merged_nums)

        # Check if the length of the merged array is odd or even
        if n % 2 == 1:
            # If odd, return the middle element as the median
            return merged_nums[n // 2]
        else:
            # If even, return the average of the two middle elements as the median
            mid1 = merged_nums[n // 2 - 1]
            mid2 = merged_nums[n // 2]
            return (mid1 + mid2) / 2.0


# Create vectors of integers for nums1 and nums2
nums1 = [1, 3, 5]
nums2 = [2, 4, 6]

# Create a Solution object
solution = Solution()

# Find the median of the two sorted arrays
median = solution.findMedianSortedArrays(nums1, nums2)

# Print the median
print("Median:", median)
