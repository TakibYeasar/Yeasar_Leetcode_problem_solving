
# Problem Link ====>>https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/

class Solution:
    def minimumAddedInteger(self, nums1: list[int], nums2: list[int]) -> int:
        nums1.sort()
        nums2.sort()
        diff = nums2[0] - nums1[0]

        for i in range(len(nums1)):
            if nums2[i] - nums1[i] != diff:
                new_diff = nums2[i] - nums1[i]

                can_achieve = any(num + new_diff >= nums2[0] for num in nums1)

                if not can_achieve:
                    return INT_MAX

        return diff


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

    min_added_integer = solution.minimumAddedInteger(nums1, nums2)

    if min_added_integer == INT_MAX:
        print("No such integer exists.")
    else:
        print("Minimum integer that needs to be added:", min_added_integer)
