// Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1 - 9 without repetition.
// Each column must contain the digits 1 - 9 without repetition.
// Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
// Note:

// A Sudoku board(partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> eachBox;
        unordered_map<char, int> row;
        unordered_map<char, int> column;
        int j = 0;
        int i = 0;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row[board[i][j]]++;
                }
                if (board[j][i] != '.')
                {
                    column[board[j][i]]++;
                }
                if (row[board[i][j]] > 1)
                    return false;
                if (column[board[j][i]] > 1)
                    return false;
            }
            row.clear();
            column.clear();
        }
        for (i = 0; i < 9; i += 3)
        {
            for (j = 0; j < 9; j += 3)
            {
                eachBox.clear();
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        if (board[x][y] != '.')
                        {
                            eachBox[board[x][y]]++;
                        }
                        if (eachBox[board[x][y]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution solution;
    bool isValid = solution.isValidSudoku(board);

    if (isValid)
    {
        cout << "The Sudoku board is valid." << endl;
    }
    else
    {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}