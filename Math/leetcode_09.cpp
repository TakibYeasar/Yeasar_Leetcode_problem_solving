// Given an integer x, return true if x is a palindrome, and false otherwise.

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        // The error message indicates that the expression 998765432 * 10 overflows the int type.This is because the int type in C++ has a
        // limited range of values, and the result of the expression is too large to be represented in that type.

        // To fix this error,you can change the type of the variables x and reversed to long long or unsigned long long.These types have a
        // larger range of values and can safely represent the result of the expression.while (temp != 0)

        while (temp != 0)
        {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        return reversed == x;
    }
};

int main()
{
    Solution isPalindrome();
    int x = 50;
    int result = isPalindrome(x);
    cout << result << endl;
    return 0;
}