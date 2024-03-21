
// Problem Link ====>>https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1); // Initialize the stack with -1 to handle edge cases

        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i); // Push the index of '(' onto the stack
            }
            else
            {
                st.pop(); // Pop the '(' index from the stack

                if (st.empty())
                {
                    st.push(i); // If the stack is empty, push the current index
                }
                else
                {
                    maxLen = max(maxLen, i - st.top()); // Calculate the length of valid parentheses
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;               // Create an instance of the Solution class
    string input = "(()))())("; // Example input
    int result = sol.longestValidParentheses(input);
    cout << "Length of the longest valid parentheses: " << result << endl;

    return 0;
}