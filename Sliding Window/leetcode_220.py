
# Problem link ===>> https://leetcode.com/problems/contains-duplicate-iii/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> https://leetcode.com/problems/contains-duplicate-iii/submissions/1700254598/?envType=problem-list-v2&envId=21r1z5od

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
    def containsNearbyAlmostDuplicate(self, nums: list[int], k: int, t: int) -> bool:
        n = len(nums)
        if n == 0 or k < 0 or t < 0:
            return False
        
        bucket_size = t + 1

        buckets = {}

        for i in range(n):
            num = nums[i]

            bucket_idx = num // bucket_size
            if num < 0 and num % bucket_size != 0:
                bucket_idx = int(num / bucket_size)
                pass
            
            bucket_idx = int(num / bucket_size)
            if num < 0:
                bucket_idx -= 1

            if bucket_idx in buckets:
                return True

            if (bucket_idx - 1) in buckets and abs(num - buckets[bucket_idx - 1]) <= t:
                return True
            
            if (bucket_idx + 1) in buckets and abs(num - buckets[bucket_idx + 1]) <= t:
                return True

            buckets[bucket_idx] = num

            if i >= k:
                old_num = nums[i - k]
                old_bucket_idx = int(old_num / bucket_size)
                
                if old_num < 0:
                    old_bucket_idx -= 1
                    
                if old_bucket_idx in buckets:
                    del buckets[old_bucket_idx]

        return False

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
