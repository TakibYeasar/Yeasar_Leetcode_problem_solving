
# Problem link ===>> https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        prefix_sum = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]

        ans = 0
        for left in range(n):
            for right in range(left, n):
                if (right - left + 1) % 2 == 1:
                    ans += prefix_sum[right + 1] - prefix_sum[left]

        return ans


if __name__ == "__main__":
    solution = Solution()
