
# Problem link ===>> https://leetcode.com/problems/number-of-provinces/description/?envType=problem-list-v2&envId=21rco0xh
# submission link == =>> https://leetcode.com/problems/number-of-provinces/submissions/1809631375/?envType=problem-list-v2&envId=21rco0xh

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
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False] * n
        count = 0
        
        def dfs(city):
            for neighbor in range(n):
                if isConnected[city][neighbor] == 1 and not visited[neighbor]:
                    visited[neighbor] = True
                    dfs(neighbor)
        
        for i in range(n):
            if not visited[i]:
                visited[i] = True
                dfs(i)
                count += 1
        return count

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
