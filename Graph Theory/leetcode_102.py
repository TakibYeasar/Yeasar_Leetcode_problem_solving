
# Problem link ===>> https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=21r18twg
# submission link == =>> https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/1792266077/?envType=problem-list-v2&envId=21r18twg

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
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        if not root:
            return res

        q = deque()
        q.append(root)

        while q:
            same_level = []

            for _ in range(len(q)):
                node = q.popleft()
                same_level.append(node.val)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(same_level)
        return res


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())


if __name__ == "__main__":
    solution = Solution()
