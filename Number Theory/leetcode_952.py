
# Problem link ===>> https://leetcode.com/problems/largest-component-size-by-common-factor/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/largest-component-size-by-common-factor/submissions/1757295009/?envType=problem-list-v2&envId=21r1b7y6

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


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> bool:
        xp, yp = self.find(x), self.find(y)
        if xp == yp:
            return False
        if self.size[xp] > self.size[yp]:
            self.parent[yp] = xp
            self.size[xp] += self.size[yp]
        else:
            self.parent[xp] = yp
            self.size[yp] += self.size[xp]
        return True


class Solution:
    def largestComponentSize(self, nums: list[int]) -> int:
        n = len(nums)
        spf = self.sieve(max(nums) + 1)
        uf = UnionFind(n)

        prime_to_index = {}
        
        for i, num in enumerate(nums):
            for p in self.getPrimes(num, spf):
                if p in prime_to_index:
                    uf.union(i, prime_to_index[p])
                else:
                    prime_to_index[p] = i

        return max(uf.size)

    def sieve(self, M: int) -> list[int]:
        spf = list(range(M + 1))
        for i in range(2, int(math.sqrt(M)) + 1):
            if spf[i] == i:
                for j in range(i * i, M + 1, i):
                    if spf[j] == j:
                        spf[j] = i
        return spf

    def getPrimes(self, x: int, spf: list[int]) -> list[int]:
        primes = []
        while x != 1:
            p = spf[x]
            primes.append(p)
            while x % p == 0:
                x //= p
        return primes

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
