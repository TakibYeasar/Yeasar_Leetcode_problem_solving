# Problem Link ====>>https://leetcode.com/problems/valid-sudoku/description/

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
