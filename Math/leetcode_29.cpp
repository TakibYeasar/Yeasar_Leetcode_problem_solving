// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
// The integer division should truncate toward zero, which means losing its fractional part.For example,
// 8.345 would be truncated to 8, and-2.7335 would be truncated to - 2.
// Return the quotient after dividing dividend by divisor.
// Note : Assume we are dealing with an environment that could only store integers within the 32-bit signed integer
//  range : [−231, 231 − 1 ].For this problem,if the quotient is strictly greater than 231 - 1, then return 231 - 1,
//  and if the quotient is strictly less than - 231, then return -231.

// ==============>>>
// Doing this problem correctly is a massive pain in the a55.
// 1. without using multiplication, division, and mod operator
// 2. Note : Assume we are dealing with an environment that could only store integers within the 32 - bit
// signed integer range : [−2 ^ 31, 2 ^ 31 − 1 ]
// Many of the solutions posted in discussions blatantly violate rule #1, which makes this problem completely trivial.
// Addressing rule #2 is the main pain point in this problem.Many of those using typed languages use longs to
// trivially bypass this.Those using python frequently forget that abs(−2 ^ 31) > 2 ^ which is overflow.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX; // Overflow case

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; // Determine sign of the result
        long long dvd = labs(dividend);                     // Use long long to handle INT_MIN case
        long long dvs = labs(divisor);

        long long quotient = 0;
        while (dvd >= dvs)
        {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return sign == 1 ? static_cast<int>(quotient) : static_cast<int>(-quotient);
    }
};

int main()
{
    Solution sol;
    int dividend = 10;
    int divisor = 3;
    int result = sol.divide(dividend, divisor);
    cout << "Result of dividing " << dividend << " by " << divisor << " is: " << result << endl;

    return 0;
}