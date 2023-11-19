# Given an integer array nums sorted in non - decreasing order, remove the duplicates in - place such that each
# unique element appears only once.The relative order of the elements should be kept the same.Then return the number
# of unique elements in nums.

def remove_duplicates(nums):
  """
  Removes duplicates from a sorted list in place.

  Args:
    nums: A list of integers.

  Returns:
    The number of unique elements in the list.
  """

  i = 0
  for j in range(1, len(nums)):
    if nums[i] != nums[j]:
      i += 1
      nums[i] = nums[j]
  return i + 1

# Example usage:

nums = [1, 1, 2, 3, 3]
length = remove_duplicates(nums)

print(length)  # prints 3
