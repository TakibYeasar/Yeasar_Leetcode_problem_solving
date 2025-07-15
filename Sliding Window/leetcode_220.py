
# Problem link ===>> https://leetcode.com/problems/contains-duplicate-iii/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> 

import collections
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
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        n = len(nums)
        if n == 0 or indexDiff < 0 or valueDiff < 0:
            return False
        buckets = collections.OrderedDict()

        for i in range(n):
            bucket_size = valueDiff + 1

            bucket = nums[i] // bucket_size
            if nums[i] < 0:
                bucket -= 1

            if bucket in buckets:
                return True

            if (bucket - 1) in buckets and abs(nums[i] - buckets[bucket - 1]) <= valueDiff:
                return True
            if (bucket + 1) in buckets and abs(nums[i] - buckets[bucket + 1]) <= valueDiff:
                return True

            buckets[bucket] = nums[i]
            if len(buckets) > indexDiff:
                old_bucket = nums[i - indexDiff] // bucket_size
                if nums[i - indexDiff] < 0:
                    old_bucket -= 1

                if old_bucket in buckets:
                    buckets.pop(old_bucket)

        return False

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
