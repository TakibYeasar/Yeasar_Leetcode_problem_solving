
// Problem link ===>> https://leetcode.com/problems/n-queens-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
private:
    // Helper function to check if placing a queen at position (row, col) is safe
    bool isSafe(int row, int col, vector<int> &board)
    {
        for (int i = 0; i < row; i++)
        {
            // Check column and diagonals for any conflicts
            if (board[i] == col || abs(board[i] - col) == abs(i - row))
            {
                return false;
            }
        }
        return true;
    }

    // Recursive helper function to count solutions
    void solve(int n, int row, vector<int> &board, int &count)
    {
        if (row == n)
        {
            count++;
            return;
        }

        // Try placing the queen in every column of the current row
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, board))
            {
                board[row] = col;                // Place queen
                solve(n, row + 1, board, count); // Recurse for the next row
                board[row] = -1;                 // Backtrack
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<int> board(n, -1); // Stores the column positions of queens for each row
        int count = 0;
        solve(n, 0, board, count); // Start solving from row 0
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        
    }
    return 0;
}