
# Problem link ===>> https://leetcode.com/problems/product-of-array-except-self/description/?envType=problem-list-v2&envId=21r1mgbr
# submission link == =>> https://leetcode.com/problems/product-of-array-except-self/submissions/1670608719/?envType=problem-list-v2&envId=21r1mgbr

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
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        products = [1] * length
        for i in range(1, length):
            products[i] = products[i - 1] * nums[i - 1]
        
        right_product = nums[-1]
        for i in range(length - 2, -1, -1):
            products[i] *= right_product
            right_product *= nums[i]
            
        return products

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
