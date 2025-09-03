
# Problem link ===>> https://leetcode.com/problems/ugly-number-ii/description/
# submission link == =>> https://leetcode.com/problems/ugly-number-ii/submissions/1758333149/

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
    def nthUglyNumber(self, n: int) -> int:
        ugly_numbers = [1]
        i2 = i3 = i5 = 0

        while len(ugly_numbers) < n:
            next2, next3, next5 = 2 * ugly_numbers[i2], 3 * ugly_numbers[i3], 5 * ugly_numbers[i5]
            next_ugly = min(next2, next3, next5)
            ugly_numbers.append(next_ugly)

            if next_ugly == next2:
                i2 += 1
            if next_ugly == next3:
                i3 += 1
            if next_ugly == next5:
                i5 += 1

        return ugly_numbers[-1]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
