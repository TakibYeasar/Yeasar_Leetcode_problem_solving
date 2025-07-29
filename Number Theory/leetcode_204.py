
# Problem link ===>> https://leetcode.com/problems/count-primes/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/count-primes/submissions/1715763179/?envType=problem-list-v2&envId=21r1b7y6

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
    def countPrimes(self, n: int) -> int:
        if n<2:
            return 0
        
        sieve = [True] * n
        sieve[0] = sieve[1] = False
        
        i =2
        while i * i < n:
            if sieve[i]:
                for j in range(i * i, n, i):
                    sieve[j] = False
            i += 1
        return sum(sieve)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
