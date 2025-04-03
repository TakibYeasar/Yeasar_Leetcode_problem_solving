
# Problem link ===>>  https://leetcode.com/problems/move-zeroes/description/
# submission link == =>> https://leetcode.com/problems/move-zeroes/submissions/1592649675/

from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        l = 0
        n = len(nums)

        for r in range(n):
            if nums[r] != 0:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1


if __name__ == "__main__":
    solution = Solution()
