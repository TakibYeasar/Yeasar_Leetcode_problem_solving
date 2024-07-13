
# Problem link ===>>  https://leetcode.com/problems/binary-search/description/

# class List:
#     def __init__(self):
#         self.data = []

#     def append(self, item):
#         self.data.append(item)

class Solution:
  def search(self, nums: list[int], target: int) -> int:
    left = 0
    right = len(nums) - 1

    while left <= right:
      mid = (left + right) // 2

      if nums[mid] == target:
        return mid
      elif nums[mid] < target:
        left = mid + 1
      else:
        right = mid - 1

    return -1


if __name__ == "__main__":
    solution = Solution()
    nums = [-1, 0, 3, 5, 9, 12]
    target = 9
    index = solution.search(nums, target)

    if index != -1:
        print("Target found at index", index)
    else:
        print("Target not found")


