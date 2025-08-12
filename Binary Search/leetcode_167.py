
# Problem link ===>> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=21r1hia6
# submission link == =>> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1731482363/?envType=problem-list-v2&envId=21r1hia6

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
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            low, high = i + 1, len(numbers) - 1
            while low <= high:
                mid = low + (high - low) // 2
                if numbers[mid] == target - numbers[i]:
                    return [i + 1, mid + 1]
                elif numbers[mid] > target - numbers[i]:
                    high = mid - 1
                else:
                    low = mid + 1
        return [-1, -1]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
