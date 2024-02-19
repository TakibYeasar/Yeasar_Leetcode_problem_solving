# Given an integer n, return the number of structurally unique BST's (binary search trees) 
# which has exactly n nodes of unique values from 1 to n.

# Solution - I (Brute-Force) [TLE]

# class Solution:
#     def numTrees(self, n: int) -> int:
#         if n <= 1:
#             return 1
#         return sum(self.numTrees(i-1) * self.numTrees(n-i) for i in range(1, n+1))


# Solution - II (Dynamic Programming - Memoization)

class Solution:
    @cache
    def numTrees(self, n: int) -> int:
        if n <= 1:
            return 1
        return sum(self.numTrees(i-1) * self.numTrees(n-i) for i in range(1, n+1))