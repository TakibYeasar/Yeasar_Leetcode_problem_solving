
// Problem Link ====>> https://leetcode.com/problems/reverse-integer/description/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }

        // Check if the reversed integer overflows the 32-bit signed integer range.
        if (rev > INT_MAX || rev < INT_MIN)
        {
            return 0;
        }
        else
        {
            return rev;
        }
    }
};

int main()
{
    int x = -12345;
    Solution solution;

    int reversed = solution.reverse(x);

    if (reversed == 0)
    {
        cout << "The reversed integer overflows the 32-bit signed integer range." << endl;
    }
    else
    {
        cout << "The reversed integer of " << x << " is: " << reversed << endl;
    }

    return 0;
}