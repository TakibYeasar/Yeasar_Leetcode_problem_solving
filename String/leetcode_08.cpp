
// Problem Link ====>> https://leetcode.com/problems/string-to-integer-atoi/description/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        int n = str.length();

        // Skip leading whitespace
        while (i < n && str[i] == ' ')
        {
            i++;
        }

        // Handle the sign
        if (i < n && (str[i] == '+' || str[i] == '-'))
        {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert the digits to an integer
        while (i < n && isdigit(str[i]))
        {
            int digit = str[i] - '0';

            // Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

int main()
{
    string str = "12345";

    Solution solution;
    int result = solution.myAtoi(str);

    cout << "The integer value of '" << str << "' is: " << result << endl;

    return 0;
}