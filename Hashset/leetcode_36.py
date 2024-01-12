# Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
# Note:

# A Sudoku board (partially filled) could be valid but is not necessarily solvable.
# Only the filled cells need to be validated according to the mentioned rules.

class Solution:
    def isValidSudoku(self, board):
        def check_duplicate(nums):
            count = {}
            for num in nums:
                if num != '.':
                    if num in count:
                        return False
                    count[num] = 1
            return True
        
        # Check rows and columns
        for i in range(9):
            if not check_duplicate(board[i]) or not check_duplicate([board[j][i] for j in range(9)]):
                return False
        
        # Check 3x3 boxes
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                nums = [board[x][y] for x in range(i, i+3) for y in range(j, j+3)]
                if not check_duplicate(nums):
                    return False
        
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
    isValid = solution.isValidSudoku(board)

    if isValid:
        print("The Sudoku board is valid.")
    else:
        print("The Sudoku board is not valid.")
