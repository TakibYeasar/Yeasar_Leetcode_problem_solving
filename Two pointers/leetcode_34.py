# Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.
# If target is not found in the array,return [ -1, -1 ].
# You must write an algorithm with O(log n) runtime complexity.

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        first, last = -1, -1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                first = mid
                last = mid
                while first > 0 and nums[first - 1] == target:
                    first -= 1
                while last < len(nums) - 1 and nums[last + 1] == target:
                    last += 1
                return [first, last]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

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
