
# Problem link ===>>  https://leetcode.com/problems/jump-game/description/
# submission link == =>> https://leetcode.com/problems/jump-game/submissions/1557315580/


from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        gas = 0
        for i, n in enumerate(nums):
            if gas < i:
                return False
            gas = max(gas, i + n)
        return True


if __name__ == "__main__":
    solution = Solution()

    nums1 = [2, 3, 1, 1, 4]
    print(solution.canJump(nums1))

    nums2 = [3, 2, 1, 0, 4]
    print(solution.canJump(nums2))
