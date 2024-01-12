// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

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