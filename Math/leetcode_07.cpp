// Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside
// the signed 32 - bit integer range[-231, 231 - 1], then return 0.Assume the environment does not allow you to store 64 -
// bit integers(signed or unsigned).

#include <iostream>
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
