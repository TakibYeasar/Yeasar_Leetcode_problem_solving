# Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.
# If target is not found in the array,return [ -1, -1 ].
# You must write an algorithm with O(log n) runtime complexity.

from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findFirst(nums, target):
            left, right = 0, len(nums) - 1
            first = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    first = mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return first

        def findLast(nums, target):
            left, right = 0, len(nums) - 1
            last = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    last = mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return last

        first = findFirst(nums, target)
        last = findLast(nums, target)
        return [first, last]


if __name__ == "__main__":
    target = int(input("Enter the target: "))
    nums = list(
        map(int, input("Enter the array elements (separated by spaces): ").split()))

    solution = Solution()
    result = solution.searchRange(nums, target)

    if result[0] == -1:
        print("Target " + str(target) + " not found in the array.")
    else:
        print("Target " + str(target) + " found at positions: " +
              str(result[0]) + " and " + str(result[1]))
