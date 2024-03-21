
// Problem Link ====>> https://leetcode.com/problems/zigzag-conversion/description/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s; // No change needed for a single row.
        }

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows)
        {
            result += row;
        }

        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution solution;
    string convertedString = solution.convert(s, numRows);

    cout << "The converted string is: " << convertedString << endl;

    return 0;
}