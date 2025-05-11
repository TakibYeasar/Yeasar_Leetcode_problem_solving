
# Problem link ===>> https://leetcode.com/problems/minimum-window-substring/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> https://leetcode.com/problems/minimum-window-substring/submissions/1631053893/

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
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        
        map = [0] * 128
        count = len(t)
        start = 0
        end =0
        min_len = float('inf')
        start_index = 0
        
        for char in t:
            map[ord(char)] += 1
        
        while end < len(s):
            if map[ord(s[end])] > 0:
                count -= 1
            map[ord(s[end])] -= 1
            end += 1

            while count == 0:
                if end - start < min_len:
                    start_index = start
                    min_len = end - start

                if map[ord(s[start])] == 0:
                    count += 1
                map[ord(s[start])] += 1
                start += 1

        return "" if min_len == float('inf') else s[start_index:start_index + min_len]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
