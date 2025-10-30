
# Problem link ===>> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=problem-list-v2&envId=21ryaww3
# submission link == =>> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/1806713926/

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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        
        root_val = preorder.pop(0)
        root = TreeNode(root_val)
        inorder_index = inorder.index(root_val)
        
        root.left = self.buildTree(preorder, inorder[:inorder_index])
        root.right = self.buildTree(preorder, inorder[inorder_index + 1:])
        return root

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
