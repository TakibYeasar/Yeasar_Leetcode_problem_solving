
# Problem link ===>>  https://leetcode.com/problems/squares-of-a-sorted-array/description/
# submission link == =>> https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1592677336/

from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l, r = 0, n - 1
        v = []

        while l <= r:
            if abs(nums[l]) > abs(nums[r]):
                v.append(nums[l] * nums[l])
                l += 1
            else:
                v.append(nums[r] * nums[r])
                r -= 1

        return v[::-1]


if __name__ == "__main__":
    solution = Solution()
