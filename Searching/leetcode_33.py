# Problem Link ====>>https://leetcode.com/problems/search-in-rotated-sorted-array/description/

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid

            # Check if left half is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # Otherwise, right half is sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1


if __name__ == "__main__":
    target = int(input("Enter the target: "))
    nums = list(
        map(int, input("Enter the array elements (separated by spaces): ").split()))

    solution = Solution()
    result = solution.search(nums, target)

    if result == -1:
        print("Target " + str(target) + " not found in the array.")
    else:
        print("Target " + str(target) + " found at index: " + str(result))
