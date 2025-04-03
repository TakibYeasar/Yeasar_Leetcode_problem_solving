
# Problem link ===>> https://leetcode.com/problems/longest-nice-subarray/description/
# submission link == =>> https://leetcode.com/problems/longest-nice-subarray/submissions/1595226226/

from typing import List


# class Solution:
#     def longestNiceSubarray(self, nums: List[int]) -> int:
#         l, r = 0, 0
#         n = len(nums)
#         cnt = [0] * 30
#         mx = 0

#         while r < n:
#             x = nums[r]
#             is_valid = True

#             for i in range(30):
#                 if x & (1 << i):
#                     cnt[i] += 1
#                     if cnt[i] >= 2:
#                         is_valid = False

#             while not is_valid:
#                 y = nums[l]
#                 l += 1

#                 for i in range(30):
#                     if y & (1 << i):
#                         cnt[i] -= 1

#                 is_valid = all(cnt[i] < 2 for i in range(30))

#             mx = max(mx, r - l + 1)
#             r += 1

#         return mx

class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        mx = 0
        n = len(nums)

        for i in range(n):
            check = 0
            for j in range(i, n):
                if check & nums[j]:  # If there's an overlapping bit, break
                    break
                else:
                    mx = max(mx, j - i + 1)
                    # Add current number to the bitwise OR mask
                    check |= nums[j]

        return mx

if __name__ == "__main__":
    solution = Solution()
