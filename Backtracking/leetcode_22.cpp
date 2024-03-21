
// Problem Link ====>>https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
        {
            return {"", ""};
        }

        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);

        return result;
    }

private:
    void generateParenthesisHelper(vector<string> &result, string current, int opening, int closing, int n)
    {
        if (closing > opening || opening > n)
        {
            return;
        }

        if (opening == n && closing == n)
        {
            result.push_back(current);
            return;
        }

        current += "(";
        generateParenthesisHelper(result, current, opening + 1, closing, n);
        current.pop_back();

        current += ")";
        generateParenthesisHelper(result, current, opening, closing + 1, n);
        current.pop_back();
    }
};

int main()
{
    // Input the number of pairs of parentheses
    int n = 3;

    // Create a Solution object
    Solution solution;

    // Generate all valid parentheses expressions of length n
    vector<string> parentheses = solution.generateParenthesis(n);

    // Print the generated parentheses expressions
    for (const string &parenthesis : parentheses)
    {
        cout << parenthesis << endl;
    }

    return 0;
}
