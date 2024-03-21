# Problem Link ====>>https://leetcode.com/problems/remove-element/description/

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
