
# Problem link ===>>  https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
# submission link == =>> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1590253312/

# from typing import List
class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def maxScore(self, C: List[int], K: int) -> int:
        best = total = sum(C[:K])
        for i in range(K-1, -1, -1):
            total += C[i + len(C) - K] - C[i]
            best = max(best, total)
        return best


if __name__ == "__main__":
    solution = Solution()
