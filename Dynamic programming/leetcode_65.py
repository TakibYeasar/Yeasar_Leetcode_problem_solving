
# Problem link ===>> https://leetcode.com/problems/valid-number/description/?envType=problem-list-v2&envId=21r4yhih
# submission link == =>> https://leetcode.com/problems/valid-number/submissions/1754886323/?envType=problem-list-v2&envId=21r4yhih

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
    def isNumber(self, S: str) -> bool:
        num, exp, sign, dec = False, False, False, False
        for c in S:
            if c >= '0' and c <= '9':
                num = True
            elif c == 'e' or c == 'E':
                if exp or not num:
                    return False
                else:
                    exp, num, sign, dec = True, False, False, False
            elif c == '+' or c == '-':
                if sign or num or dec:
                    return False
                else:
                    sign = True
            elif c == '.':
                if dec or exp:
                    return False
                else:
                    dec = True
            else:
                return False
        return num

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
