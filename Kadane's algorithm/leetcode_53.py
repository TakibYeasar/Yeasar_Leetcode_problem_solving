
# Problem link ===>>  https://leetcode.com/problems/maximum-subarray/description/
# submission link == =>> https://leetcode.com/problems/maximum-subarray/submissions/1503046449/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def maxSubArray(self, nums):
        dp = [[0]*len(nums) for i in range(2)]
        dp[0][0], dp[1][0] = nums[0], nums[0]
        for i in range(1, len(nums)):
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1])
            dp[0][i] = max(dp[0][i-1], dp[1][i])
        return dp[0][-1]


if __name__ == "__main__":
    solution = Solution()
