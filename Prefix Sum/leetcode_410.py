
# Problem link ===>> https://leetcode.com/problems/split-array-largest-sum/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/split-array-largest-sum/submissions/1851139313/?envType=problem-list-v2&envId=21r1mgbr

import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, OrderedDict, Counter
from functools import lru_cache, reduce
from itertools import permutations, combinations, accumulate
from typing import List, Tuple, Dict, Set, Optional, Union, Any

MOD = 10**9 + 7
INF = float('inf')
input = sys.stdin.read
print = sys.stdout.write


class Solution:
    def helper(self, nums: List[int], perK: int, k: int) -> bool:
        count = 1
        sum = 0
        for num in nums:
            if (sum+num > perK):
                count += 1
                sum = num
            else:
                sum += num

        return count <= k

    def splitArray(self, nums: List[int], k: int) -> int:
        high = sum(nums)
        low = max(nums)
        soln = 0
        while (low <= high):
            mid = low + (high-low)//2
            if (self.helper(nums, mid, k)):
                soln = mid
                high = mid-1
            else:
                low = mid + 1

        return soln

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
