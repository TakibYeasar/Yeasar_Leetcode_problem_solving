// Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

// ============>>>
// This solution utilizes a backtracking algorithm to generate all valid parentheses combinations.The helper function generateParenthesisHelper
// () recursively explores the possible placements of opening and closing parentheses, ensuring that the number of opening parentheses never
//  exceeds the total number of parentheses(n) and that the number of closing parentheses never exceeds the number of opening parentheses.When
//  a valid combination is formed, it is added to the result vector.

// Here's a breakdown of the solution:
// Base Case : If n is zero, the only valid parentheses combination is the empty string.
// Recursive Calls : The helper function generateParenthesisHelper() takes the current parentheses string,
// the number of opening parentheses, the number of closing parentheses, and the total number of parentheses as arguments.
// a.Invalid Case : If the number of closing parentheses is greater than the number of opening parentheses
// or the number of opening parentheses is greater than the total number of parentheses, the function returns.
// b.Valid Combination : If both the number of opening and closing parentheses equals the total number of parentheses,
// the current parentheses string is a valid combination and is added to the result vector.
// c.Exploring Opening Parentheses : The function recursively calls itself,
// adding an opening parenthesis to the current string and updating the opening and closing parentheses counts.
// d.Exploring Closing Parentheses : The function recursively calls itself,
// adding a closing parenthesis to the current string and updating the opening and closing parentheses counts.
// e.Backtracking : After both recursive calls,
// the function removes the added parentheses from the current string to preserve the original state.
// Main Function : The main function calls the helper function generateParenthesisHelper() to generate all valid parentheses
// combinations and returns the result vector.

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
