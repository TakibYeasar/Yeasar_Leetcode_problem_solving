
# Problem link ===>> https://leetcode.com/problems/the-kth-factor-of-n/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/the-kth-factor-of-n/submissions/1847596373/?envType=problem-list-v2&envId=21r1b7y6

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
    def kthFactor(self, n: int, k: int) -> int:
        cnt = 0
        for i in range(1, n+1):
            if n % i == 0:
                cnt += 1
                if cnt == k:
                    return i
        return -1

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
