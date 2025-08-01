
# Problem link ===>> https://leetcode.com/problems/sliding-window-maximum/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> https://leetcode.com/problems/sliding-window-maximum/submissions/1718398477/?envType=problem-list-v2&envId=21r1z5od

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
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0:
            return []

        n = len(nums)
        if k == 1:
            return nums

        deq = deque()
        result = []

        for i in range(n):
            if deq and deq[0] < i - k + 1:
                deq.popleft()

            while deq and nums[deq[-1]] < nums[i]:
                deq.pop()

            deq.append(i)

            if i >= k - 1:
                result.append(nums[deq[0]])

        return result

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
