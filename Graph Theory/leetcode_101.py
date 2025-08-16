
# Problem link ===>> https://leetcode.com/problems/symmetric-tree/description/?envType=problem-list-v2&envId=21r18twg
# submission link == =>> https://leetcode.com/problems/symmetric-tree/submissions/1737313368/?envType=problem-list-v2&envId=21r18twg

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def is_mirror(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
            if not t1 and not t2:
                return True
            if not t1 or not t2:
                return False
            return (t1.val == t2.val and
                    is_mirror(t1.right, t2.left) and
                    is_mirror(t1.left, t2.right))
        return is_mirror(root.left, root.right)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
