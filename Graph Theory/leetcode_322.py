
# Problem link ===>> https://leetcode.com/problems/reconstruct-itinerary/description/?envType=problem-list-v2&envId=21rco0xh
# submission link == =>> https://leetcode.com/problems/reconstruct-itinerary/submissions/1725752461/?envType=problem-list-v2&envId=21rco0xh

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
    def __init__(self):
        self.flightGraph = defaultdict(list)
        self.itinerary = []
    
    def dfs(self, airport: str)-> None:
        while self.flightGraph[airport]:
            next_airport = self.flightGraph[airport].pop()
            self.dfs(next_airport)
        self.itinerary.append(airport)
    
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        for src, dest in tickets:
            self.flightGraph[src].append(dest)
        
        for src in self.flightGraph:
            self.flightGraph[src].sort(reverse=True)
        
        self.dfs("JFK")
        return self.itinerary[::-1]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())

if __name__ == "__main__":
    solution = Solution()
