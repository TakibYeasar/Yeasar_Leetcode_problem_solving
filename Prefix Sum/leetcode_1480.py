
# Problem link ===>> https://leetcode.com/problems/running-sum-of-1d-array/description/

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range (n):
            nums[i] += nums[i - 1]
        return nums


if __name__ == "__main__":
    solution = Solution()
