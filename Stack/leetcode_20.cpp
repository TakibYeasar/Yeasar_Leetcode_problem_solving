// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if : Open brackets must be closed by the same type of brackets.Open brackets must 
// be closed in the correct order.Every close bracket has a corresponding open bracket of the same type.

#include <iostream>
#include <unordered_map>
#include <stack>

    using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> closing_brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stk;

        for (char c : s)
        {
            if (closing_brackets.count(c))
            {
                if (stk.empty() || stk.top() != closing_brackets[c])
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};