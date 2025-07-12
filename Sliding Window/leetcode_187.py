
# Problem link ===>> https://leetcode.com/problems/repeated-dna-sequences/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> https://leetcode.com/problems/repeated-dna-sequences/submissions/1695486516/?envType=problem-list-v2&envId=21r1z5od

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
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = {}
        result = []

        for i in range(len(s) - 9):
            substr = s[i:i+10]
            seen[substr] = seen.get(substr, 0) + 1
            if seen[substr] == 2:
                result.append(substr)

        return result

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
