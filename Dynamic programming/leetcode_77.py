
# Problem link ===>> https://leetcode.com/problems/combinations/?envType=problem-list-v2&envId=21r4yhih
# submission link == =>> https://leetcode.com/problems/combinations/submissions/1783364985/?envType=problem-list-v2&envId=21r4yhih

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
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        
        def backtrack(start, comb):
            if len(comb) == k:
                res.append(comb[:])
                return

            for i in range(start, n+1):
                comb.append(i)
                backtrack(i+1, comb)
                comb.pop()
        backtrack(1, [])
        return res

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
