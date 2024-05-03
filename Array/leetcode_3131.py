
# Problem Link ====>> https://leetcode.com/problems/find-the-integer-added-to-array-i/description/

class Solution:
    def addedInteger(self, nums1: list[int], nums2: list[int]) -> int:
        nums1.sort()
        nums2.sort()
        return nums2[0] - nums1[0]


if __name__ == "__main__":
    solution = Solution()
    
    n = int(input("Enter the size of both arrays: "))

    nums1 = []
    nums2 = []

    print("Enter elements for the first array:")
    for i in range(n):
        num = int(input())
        nums1.append(num)

    print("Enter elements for the second array:")
    for i in range(n):
        num = int(input())
        nums2.append(num)

    difference = solution.addedInteger(nums1, nums2)

    print("Difference between smallest elements:", difference)
