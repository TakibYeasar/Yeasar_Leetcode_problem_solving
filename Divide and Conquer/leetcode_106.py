
# Problem link ===>> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=problem-list-v2&envId=21ryaww3
# submission link == =>> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1804320141/?envType=problem-list-v2&envId=21ryaww3

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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder:
            return None

        root_val = postorder.pop()
        root = TreeNode(root_val)

        inorder_index = inorder.index(root_val)

        root.right = self.buildTree(inorder[inorder_index + 1:], postorder)
        root.left = self.buildTree(inorder[:inorder_index], postorder)

        return root

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
