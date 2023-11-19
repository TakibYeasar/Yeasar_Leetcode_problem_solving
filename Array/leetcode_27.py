# Given an integer array nums and an integer val, remove all occurrences of val in nums in - place.The order of the elements
# may be changed.Then return the number of elements in nums which are not equal to val.
# Consider the number of elements in nums which are not equal to val be k,to get accepted, you need to do the following things :
# Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
# The remaining elements of nums are not important as well as the size of nums.Return k.

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        """
        Removes all occurrences of the value `val` from the vector `nums`.

        Args:
            nums: The vector to remove the value `val` from.
            val: The value to remove from the vector `nums`.

        Returns:
            The new size of the vector `nums`.
        """

        # Check if the vector is empty.
        if not nums:
            return 0

        # Iterate over the vector and remove all occurrences of the value `val`.
        i = 0
        j = len(nums) - 1
        while i <= j:
            if nums[i] == val:
                nums[i] = nums[j]
                j -= 1
            else:
                i += 1

        # Return the new size of the vector.
        return i

solution = Solution()
nums = [3, 2, 2, 3]
val = 3
newSize = solution.removeElement(nums, val)

print(newSize)  # prints 2
