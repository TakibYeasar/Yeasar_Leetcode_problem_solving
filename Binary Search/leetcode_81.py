
# Problem link ===>> https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/?envType=problem-list-v2&envId=21r1hia6
# submission link == =>> https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/1640413560/?envType=problem-list-v2&envId=21r1hia6

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
    def search(self, nums: List[int], target: int) -> bool:
        low, high = 0, len(nums) - 1

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return True

            if nums[low] == nums[mid]:
                low += 1
                continue

            if nums[low] <= nums[mid]:
                if nums[low] <= target <= nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] <= target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1

        return False

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
