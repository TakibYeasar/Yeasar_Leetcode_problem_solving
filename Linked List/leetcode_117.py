
# Problem link ===>> https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=problem-list-v2&envId=21rc2cs6
# submission link == =>> https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/1815926851/?envType=problem-list-v2&envId=21rc2cs6

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

class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root

        from collections import deque
        q = deque([root])

        while q:
            size = len(q)
            for i in range(size):
                node = q.popleft()
                if i < size - 1:
                    node.next = q[0]
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return root

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
