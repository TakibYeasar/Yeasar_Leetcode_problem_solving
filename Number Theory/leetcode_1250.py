
# Problem link ===>> https://leetcode.com/problems/check-if-it-is-a-good-array/description/?envType=problem-list-v2&envId=21r1b7y6
# submission link == =>> https://leetcode.com/problems/check-if-it-is-a-good-array/submissions/1761677791/?envType=problem-list-v2&envId=21r1b7y6

import sys
import math
from math import gcd
from functools import reduce
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
    def isGoodArray(self, nums: List[int]) -> bool:

        def find_gcd_of_list(arr: List[int]) -> int:
            return reduce(gcd, arr)

        return find_gcd_of_list(nums) == 1

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
