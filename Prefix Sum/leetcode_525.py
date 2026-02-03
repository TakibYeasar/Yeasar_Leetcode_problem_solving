
# Problem link ===>> https://leetcode.com/problems/contiguous-array/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/random-pick-with-weight/submissions/1906703778/?envType=problem-list-v2&envId=21r1mgbr

import sys
import math
import bisect
import heapq
import random
from collections import defaultdict, deque, OrderedDict, Counter
from functools import lru_cache, reduce
from itertools import permutations, combinations, accumulate
from typing import List, Tuple, Dict, Set, Optional, Union, Any

MOD = 10**9 + 7
INF = float('inf')
input = sys.stdin.read
print = sys.stdout.write


class Solution:

    def __init__(self, w: List[int]):
        self.prefix = []
        total = 0
        for weight in w:
            total += weight
            self.prefix.append(total)
        self.total = total

    def pickIndex(self) -> int:
        rand = random.randint(1, self.total)
        return bisect.bisect_left(self.prefix, rand)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
