
# Problem link ===>> https://leetcode.com/problems/minimum-height-trees/description/?envType=problem-list-v2&envId=21rco0xh
# submission link == =>>  https://leetcode.com/problems/minimum-height-trees/submissions/1711306149/?envType=problem-list-v2&envId=21rco0xh

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


class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n < 3:
            return list(range(n))

        adjacency_list = [set() for _ in range(n)]
        for a, b in edges:
            adjacency_list[a].add(b)
            adjacency_list[b].add(a)

        leaves = [i for i in range(n) if len(adjacency_list[i]) == 1]

        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                neighbor = adjacency_list[leaf].pop()
                adjacency_list[neighbor].remove(leaf)
                if len(adjacency_list[neighbor]) == 1:
                    new_leaves.append(neighbor)
            leaves = new_leaves

        return leaves

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
