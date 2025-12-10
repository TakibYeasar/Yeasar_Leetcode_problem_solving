
# Problem link ===>> https://leetcode.com/problems/range-sum-query-2d-immutable/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/1850165616/?envType=problem-list-v2&envId=21r1mgbr

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


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if not matrix or not matrix[0]:
            self.prefixSum = [[]]
            return
        
        m, n = len(matrix), len(matrix[0])
        self.prefixSum = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                self.prefixSum[i+1][j+1] = (self.prefixSum[i][j+1]
                                            + self.prefixSum[i+1][j]
                                            - self.prefixSum[i][j]
                                            + matrix[i][j])

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (self.prefixSum[row2+1][col2+1]
                - self.prefixSum[row2+1][col1]
                - self.prefixSum[row1][col2+1]
                + self.prefixSum[row1][col1])

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = NumMatrix()
