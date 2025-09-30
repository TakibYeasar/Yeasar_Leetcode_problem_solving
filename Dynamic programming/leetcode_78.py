
# Problem link ===>> https://leetcode.com/problems/subsets/?envType=problem-list-v2&envId=21r4yhih
# submission link == =>> https://leetcode.com/problems/subsets/submissions/1787365941/?envType=problem-list-v2&envId=21r4yhih

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
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []

        def backtrack(index):
            if index >= len(nums):
                res.append(subset.copy())
                return

            # Include the number at the current index
            subset.append(nums[index])
            backtrack(index + 1)

            # Exclude the number at the current index
            subset.pop()
            backtrack(index + 1)

        backtrack(0)
        return res

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
