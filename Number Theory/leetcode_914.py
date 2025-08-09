
# Problem link ===>> https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/submissions/1726941170/?envType=problem-list-v2&envId=21r1b7y6

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
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a: int, b: int) -> int:
            while b:
                a, b = b, a % b
            return a
        count = Counter(deck).values()
        return reduce(gcd, count) > 1

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
