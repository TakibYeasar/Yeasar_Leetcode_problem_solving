
# Problem link ===>> https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=21r1hia6
# submission link == =>> https://leetcode.com/problems/missing-number/submissions/1733875912/?envType=problem-list-v2&envId=21r1hia6

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
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        ans  = 0
        
        for i in range(n + 1):
            ans ^= i
        
        for num in nums:
            ans ^= num
        
        return ans

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
