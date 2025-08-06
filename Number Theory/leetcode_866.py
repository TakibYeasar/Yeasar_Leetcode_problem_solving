
# Problem link ===>> https://leetcode.com/problems/prime-palindrome/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/prime-palindrome/submissions/1723264689/?envType=problem-list-v2&envId=21r1b7y6

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
    def primePalindrome(self, n: int) -> int:
        def is_prime(x: int) -> bool:
            if x < 2 or x % 2 == 0:
                return x == 2
            for i in range(3, int(math.isqrt(x)) + 1, 2):
                if x % i == 0:
                    return False
            return True

        if 8 <= n <= 11:
            return 11

        for x in range(1, 100000):
            s = str(x)
            pal = int(s + s[-2::-1])
            if pal >= n and is_prime(pal):
                return pal

        return -1

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
