
# Problem link ===>> https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/?envType=problem-list-v2&envId=21rc2cs6
# submission link == =>> https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/1815927961/?envType=problem-list-v2&envId=21rc2cs6

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
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        head = root
        while root:
            cur, root = root, root.left
            while cur:
                if cur.left:
                    cur.left.next = cur.right
                    if cur.next:
                        cur.right.next = cur.next.left
                else:
                    break
                cur = cur.next

        return head

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
