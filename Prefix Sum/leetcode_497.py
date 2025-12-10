
# Problem link ===>> https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1852061016/?envType=problem-list-v2&envId=21r1mgbr

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

    def __init__(self, rects: List[List[int]]):
        w = [(x2-x1+1)*(y2-y1+1) for x1, y1, x2, y2 in rects]
        self.weights = [i/sum(w) for i in accumulate(w)]
        self.rects = rects

    def pick(self) -> List[int]:
        n_rect = bisect.bisect(self.weights, random.random())
        x1, y1, x2, y2 = self.rects[n_rect]
        return [random.randint(x1, x2), random.randint(y1, y2)]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
