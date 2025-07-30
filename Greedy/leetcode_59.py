
# Problem link ===>> https://leetcode.com/problems/spiral-matrix-ii/description/?envType=problem-list-v2&envId=21r4yhih
# submission link == =>> https://leetcode.com/problems/spiral-matrix-ii/submissions/1717266509/?envType=problem-list-v2&envId=21r4yhih

from typing import List
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
    def generateMatrix(self, n: int) -> List[List[int]]:
        def is_out_of_bound(row, col):
            return row < 0 or row >= n or col < 0 or col >= n

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        result = [[0] * n for _ in range(n)]
        curr_dir_idx = 0
        row, col = 0, 0

        for i in range(1, n * n + 1):
            result[row][col] = i

            next_row = row + dirs[curr_dir_idx][0]
            next_col = col + dirs[curr_dir_idx][1]

            if is_out_of_bound(next_row, next_col) or result[next_row][next_col] != 0:
                curr_dir_idx = (curr_dir_idx + 1) % 4
                next_row = row + dirs[curr_dir_idx][0]
                next_col = col + dirs[curr_dir_idx][1]

            row, col = next_row, next_col

        return result


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
