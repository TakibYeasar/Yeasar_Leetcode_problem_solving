
# Problem link ===>> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=problem-list-v2&envId=21rc2cs6
# submission link == =>> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1810339443/?envType=problem-list-v2&envId=21rc2cs6

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

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        current = root
        
        while current:
            if current.left:
                predecessor = current.left
                while predecessor.right:
                    predecessor = predecessor.right
                predecessor.right = current.right
                current.right = current.left
                current.left = None
            current = current.right

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
