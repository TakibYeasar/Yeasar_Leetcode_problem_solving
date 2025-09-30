
# Problem link ===>> https://leetcode.com/problems/set-matrix-zeroes/?envType=problem-list-v2&envId=21r4yhih
# submission link == =>> https://leetcode.com/problems/set-matrix-zeroes/submissions/1787334098/?envType=problem-list-v2&envId=21r4yhih

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
    def setZeroes(self, matrix: List[List[int]]) -> None:
        zeroinFirstCol = False
        for row in range(len(matrix)):
            if matrix[row][0] == 0:
                zeroinFirstCol = True
            for col in range(1, len(matrix[0])):
                if matrix[row][col] == 0:
                    matrix[row][0] = 0
                    matrix[0][col] = 0

        for row in range(len(matrix) - 1, -1, -1):
            for col in range(len(matrix[0]) - 1, 0, -1):
                if matrix[row][0] == 0 or matrix[0][col] == 0:
                    matrix[row][col] = 0
            if zeroinFirstCol:
                matrix[row][0] = 0

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
