
# Problem link ===>> https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> 

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
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = -math.inf
        for r1 in range(m):
            arr = [0] * n
            for r2 in range(r1, m):
                for c in range(n):
                    arr[c] += matrix[r2][c]
                ans = max(ans, self.maxSumSubAarray(arr, n, k))
        return ans

    def maxSumSubAarray(self, arr, n, k):
        right = 0
        seen = SortedList([0])
        ans = -math.inf
        for i in range(n):
            right += arr[i]
            left = self.ceiling(seen, right - k)
            if left != None:
                ans = max(ans, right - left)
            seen.add(right)
        return ans

    def ceiling(self, sortedList, key):
        idx = sortedList.bisect_left(key)
        if idx < len(sortedList):
            return sortedList[idx]
        return None

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
