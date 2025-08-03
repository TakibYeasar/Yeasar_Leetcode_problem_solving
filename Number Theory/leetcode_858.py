
# Problem link ===>> https://leetcode.com/problems/mirror-reflection/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/mirror-reflection/submissions/1722003879/?envType=problem-list-v2&envId=21r1b7y6

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
    def lcm(self, x, y):
        return x * y // self.gcd(x, y)

    def gcd(self, x, y):
        while y:
            x, y = y, x % y
        return abs(x)

    def mirrorReflection(self, p: int, q: int) -> int:
        time_for_reflection = self.lcm(p, q)
        is_right_side = True if time_for_reflection/q % 2 == 1 else False
        is_top_side = True if time_for_reflection/p % 2 == 1 else False

        if is_right_side and is_top_side:
            return 1
        elif not is_right_side and is_top_side:
            return 2

        return 0

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
