
// Problem Link ====>>https://leetcode.com/problems/divide-two-integers/description/

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