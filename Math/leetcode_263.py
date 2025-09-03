
# Problem link ===>> https://leetcode.com/problems/ugly-number/description/
# submission link == =>>  https://leetcode.com/problems/ugly-number/submissions/1758258459/

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
    def isUgly(self, n: int) -> bool:
        for p in [2, 3, 5]:
            while n > 0 and n % p == 0:
                n //= p
        return n == 1

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
