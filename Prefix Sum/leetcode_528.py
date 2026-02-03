
# Problem link ===>> https://leetcode.com/problems/random-pick-with-weight/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/contiguous-array/submissions/1906922156/?envType=problem-list-v2&envId=21r1mgbr

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
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_sum = 0
        index_map = {0: -1}
        max_length = 0

        for i, num in enumerate(nums):
            prefix_sum += 1 if num == 1 else -1

            if prefix_sum in index_map:
                max_length = max(max_length, i - index_map[prefix_sum])
            else:
                index_map[prefix_sum] = i

        return max_length

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
