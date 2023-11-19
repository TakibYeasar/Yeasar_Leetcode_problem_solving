# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution,and you may not use the same element twice.
#  can return the answer in any order.



# Solution 2: (Two-pass Hash Table)
class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    numMap = {}
    n = len(nums)

    # Build the hash table
    for i in range(n):
      numMap[nums[i]] = i

    # Find the complement
    for i in range(n):
      complement = target - nums[i]
      if complement in numMap and numMap[complement] != i:
        return [i, numMap[complement]]

    return []  # No solution found


# Solution 3: (One-pass Hash Table)
class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    numMap = {}
    n = len(nums)

    for i in range(n):
      complement = target - nums[i]
      if complement in numMap:
        return [numMap[complement], i]
      numMap[nums[i]] = i

    return []  # No solution found
