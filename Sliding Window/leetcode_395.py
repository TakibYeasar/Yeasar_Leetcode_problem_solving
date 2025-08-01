
# Problem link ===>> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/?envType=problem-list-v2&envId=21r1z5od
# submission link == =>> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/submissions/1719721832/?envType=problem-list-v2&envId=21r1z5od

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
    def getUniqueCharCount(self, s: str) -> int:
        seen = [False] * 26
        unique = 0
        for ch in s:
            idx = ord(ch) - ord('a')
            if not seen[idx]:
                seen[idx] = True
                unique += 1
        return unique

    def longestSubstring(self, s: str, k: int) -> int:
        max_unique = self.getUniqueCharCount(s)
        result = 0

        for target_unique in range(1, max_unique + 1):
            freq = [0] * 26
            start = end = 0
            unique = count_at_least_k = 0

            while end < len(s):
                if unique <= target_unique:
                    idx = ord(s[end]) - ord('a')
                    if freq[idx] == 0:
                        unique += 1
                    freq[idx] += 1
                    if freq[idx] == k:
                        count_at_least_k += 1
                    end += 1
                else:
                    idx = ord(s[start]) - ord('a')
                    if freq[idx] == k:
                        count_at_least_k -= 1
                    freq[idx] -= 1
                    if freq[idx] == 0:
                        unique -= 1
                    start += 1

                if unique == target_unique and unique == count_at_least_k:
                    result = max(result, end - start)

        return result


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
