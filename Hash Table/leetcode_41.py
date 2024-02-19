# Given an unsorted integer array nums, return the smallest missing positive integer.

# You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)

        # 1. mark numbers (num <= 0) and (num > n) with a special marker number (n+1)
        # (we can ignore those because if all numbers are > n then we'll simply return 1)
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = n + 1

        # note: all numbers in the array are now positive, and in the range 1..n+1

        # 2. mark each cell appearing in the array, by converting the index for that number to negative
        for i in range(n):
            num = abs(nums[i])

            if num > n:
                continue
            # -1 for zero index-based array (so the number 1 will be at pos 0)
            num -= 1
            if nums[num] > 0:
                # prevents double negative operations
                nums[num] = -1 * nums[num]

        # 3. find the first cell which isn't negative (doesn't appear in the array)
        for i in range(n):
            if nums[i] >= 0:
                return i + 1

        # 4. no positive numbers were found, which means the array contains all numbers 1..n
        return n + 1


# Example usage
nums = [3, 4, -1, 1]
solution = Solution()
missing_positive = solution.firstMissingPositive(nums)
print(f"First missing positive: {missing_positive}")
