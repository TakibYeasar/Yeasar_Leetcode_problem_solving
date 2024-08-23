
# Problem link ===>>  https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        ans = 0

        for i in range(n // 2):
            for j in range(m // 2):
                x = grid[i][j]
                x += grid[n - i - 1][j]
                x += grid[n - i - 1][m - j - 1]
                x += grid[i][m - j - 1]
                ans += min(x, 4 - x)

        c = 0
        cnt = 0

        if n % 2 == 1:
            for j in range(m // 2):
                if grid[n // 2][j] != grid[n // 2][m - j - 1]:
                    ans += 1
                    cnt += 1
                if grid[n // 2][j] == grid[n // 2][m - j - 1] and grid[n // 2][j] == 1:
                    c += 1

        if m % 2 == 1:
            for j in range(n // 2):
                if grid[j][m // 2] != grid[n - j - 1][m // 2]:
                    ans += 1
                    cnt += 1
                if grid[j][m // 2] == grid[n - j - 1][m // 2] and grid[j][m // 2] == 1:
                    c += 1

        if c % 2 == 1 and cnt == 0:
            ans += 2

        if n % 2 == 1 and m % 2 == 1 and grid[n // 2][m // 2] == 1:
            ans += 1

        return ans


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
