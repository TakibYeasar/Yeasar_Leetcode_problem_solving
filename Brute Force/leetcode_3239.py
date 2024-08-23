
# Problem link ===>>  https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        rows = 0
        cols = 0

        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            for j in range(m // 2):
                if grid[i][j] != grid[i][m - j - 1]:
                    rows += 1

        for i in range(m):
            for j in range(n // 2):
                if grid[j][i] != grid[n - j - 1][i]:
                    cols += 1

        return min(rows, cols)


def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        grid = []
        for i in range(n):
            grid.append(list(map(int, input().split())))
        sol = Solution()
        print(sol.minFlips(grid))


if __name__ == "__main__":
    solution = Solution()
