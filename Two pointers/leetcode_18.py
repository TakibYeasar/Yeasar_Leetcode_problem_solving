# Problem Link ====>>https://leetcode.com/problems/4sum/description/


# ===================>>>✔️ Solution 2 : Sort then Two Pointers

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)
        
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = set()
        for i in range(n):
            for j in range(i+1, n):
                l, r = j + 1, n - 1
                remain = target - nums[i] - nums[j]
                while l < r:
                    if nums[l] + nums[r] == remain:
                        ans.add((nums[i], nums[j], nums[l], nums[r]))
                        l += 1
                        r -= 1
                    elif nums[l] + nums[r] > remain:
                        r -= 1
                    else:
                        l += 1
        return ans
    

