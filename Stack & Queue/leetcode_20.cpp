
// Problem Link ====>>https://leetcode.com/problems/valid-parentheses/description/

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

int main()
{
    string s = "()";
    Solution solution;

    bool isValid = solution.isValid(s);

    if (isValid)
    {
        cout << "The string " << s << " is valid." << endl;
    }
    else
    {
        cout << "The string " << s << " is not valid." << endl;
    }

    return 0;
}