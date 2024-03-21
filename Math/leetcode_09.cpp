
// Problem Link ====>> https://leetcode.com/problems/palindrome-number/description/

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
    int x = 998765432;
    Solution solution;

    bool isPal = solution.isPalindrome(x);

    if (isPal == true)
    {
        cout << "The integer " << x << " is a palindrome." << endl;
    }
    else
    {
        cout << "The integer " << x << " is not a palindrome." << endl;
    }

    return 0;
}