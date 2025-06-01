
# Problem link ===>> https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=21r1hia6
# submission link == =>> https://leetcode.com/problems/sqrtx/submissions/1638490609/?envType=problem-list-v2&envId=21r1hia6

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
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        left, right = 1, x
        while left <= right:
            mid = (left + right) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                left = mid + 1
            else:
                right = mid - 1
        return right

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
