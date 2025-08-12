
# Problem link ===>> https://leetcode.com/problems/search-a-2d-matrix-ii/description/?envType=problem-list-v2&envId=21r1hia6
# submission link == =>> https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1732628879/?envType=problem-list-v2&envId=21r1hia6

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
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r = 0
        c = len(matrix[0]) - 1
        while r < len(matrix) and c >= 0:
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] < target:
                r += 1
            else:
                c -= 1
        return False

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
