# Write a program to solve a Sudoku puzzle by filling the empty cells.
# A sudoku solution must satisfy all of the following rules:
# Each of the digits 1-9 must occur exactly once in each row.
# Each of the digits 1-9 must occur exactly once in each column.
# Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
# The '.' character indicates empty cells.

class Solution:
   def __init__(self):
       self.result = [[0 for _ in range(9)] for _ in range(9)]
       self.modifiable = [[False for _ in range(9)] for _ in range(9)]

   def solveSudoku(self, board: List[List[str]]) -> None:
       self.markModifiable(board)
       self.recurse(0)
       for i in range(9):
           for j in range(9):
               board[i][j] = str(self.result[i][j])

   def markModifiable(self, board: List[List[str]]) -> None:
       for i in range(9):
           for j in range(9):
               self.modifiable[i][j] = (board[i][j] == '.')
               if not self.modifiable[i][j]:
                   self.result[i][j] = int(board[i][j])

   def recurse(self, idx: int) -> bool:
       if idx == 81:
           return True

       row = idx // 9
       column = idx % 9

       for candidate in range(1, 10):
           if self.modifiable[row][column]:
               self.result[row][column] = candidate
               if self.isValid(row, column) and self.recurse(idx + 1):
                   return True
           elif self.recurse(idx + 1):
               return True
       self.result[row][column] = 0
       return False

   def isValid(self, i: int, j: int) -> bool:
       return self.isValidRow(i) and self.isValidColumn(j) and self.isValidBlock(i, j)

   def isValidRow(self, i: int) -> bool:
       seen = [False] * 10
       for j in range(9):
           value = self.result[i][j]
           if seen[value] and value != 0:
               return False
           seen[value] = True
       return True

   def isValidColumn(self, j: int) -> bool:
       seen = [False] * 10
       for i in range(9):
           value = self.result[i][j]
           if seen[value] and value != 0:
               return False
           seen[value] = True
       return True

   def isValidBlock(self, i: int, j: int) -> bool:
       seen = [False] * 10
       for row in range((i // 3) * 3, (i // 3) * 3 + 3):
           for column in range((j // 3) * 3, (j // 3) * 3 + 3):
               value = self.result[row][column]
               if seen[value] and value != 0:
                   return False
               seen[value] = True
       return True


if __name__ == "__main__":
   board = [
       ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
       ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
       ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
       ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
       ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
       ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
       ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
       ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
       ['.', '.', '.', '.', '8', '.', '.', '7', '9']
   ]

   solution = Solution()
   solution.solveSud
