
# Problem link ===>> https://leetcode.com/problems/n-queens-ii/description/
# submission link == =>> https://leetcode.com/problems/n-queens-ii/submissions/1501886713/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def totalNQueens(self, n: int) -> int:
        def backtrack(row: int):
            if row == n:
                nonlocal count
                count += 1
                return

            for col in range(n):
                if col in cols or row - col in diag1 or row + col in diag2:
                    continue

                # Place the queen
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)

                # Recurse for the next row
                backtrack(row + 1)

                # Backtrack: remove the queen
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        cols = set()  # Columns under attack
        diag1 = set()  # \ diagonals under attack
        diag2 = set()  # / diagonals under attack
        count = 0

        backtrack(0)
        return count



if __name__ == "__main__":
    solution = Solution()
