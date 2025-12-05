
# Problem link ===>> https://leetcode.com/problems/simplified-fractions/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/simplified-fractions/submissions/1844237424/?envType=problem-list-v2&envId=21r1b7y6

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
    def simplifiedFractions(self, n: int) -> List[str]:
        res = []
        for den in range(2, n + 1):
            for num in range(1, den):
                if math.gcd(num, den) == 1:
                    res.append(f"{num}/{den}")
        return res

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
