
# Problem link ===>>  https://leetcode.com/problems/jump-game-ii/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def jump(self, nums: List[int]) -> int:
        near = far = jumps = 0

        while far < len(nums)-1:
            farthest = 0
            for i in range(near, far+1):
                farthest = max(farthest, i+nums[i])

            near = far+1
            far = farthest
            jumps += 1

        return jumps


if __name__ == "__main__":
    solution = Solution()
