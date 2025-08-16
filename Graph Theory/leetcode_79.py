
# Problem link ===>> https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=21r1dm61
# submission link == =>> https://leetcode.com/problems/word-search/submissions/1737445417/?envType=problem-list-v2&envId=21r1dm61

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
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        visited = set()
        
        def dfs(r: int, c: int, index: int) -> bool:
            if index == len(word):
                return True
            if (r < 0 or r >= rows or c < 0 or c >= cols or 
                board[r][c] != word[index] or (r, c) in visited):
                return False
            
            visited.add((r, c))
            found = (dfs(r + 1, c, index + 1) or 
                     dfs(r - 1, c, index + 1) or 
                     dfs(r, c + 1, index + 1) or 
                     dfs(r, c - 1, index + 1))
            visited.remove((r, c))
            return found
        
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == word[0]:
                    if dfs(r, c, 0):
                        return True
        return False
    

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
