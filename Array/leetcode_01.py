# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution,and you may not use the same element twice.
#  can return the answer in any order.

# Solution 1: (Brute Force)
def two_sum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []


nums = [2, 7, 11, 15]
target = 9

result = two_sum(nums, target)

if result:
    print("Indices of the two numbers that add up to the target:",
          result[0], result[1])
else:
    print("No solution found.")


