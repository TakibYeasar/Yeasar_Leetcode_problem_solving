// You are climbing a staircase.It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
        {
            return n;
        }

        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    int n = 5;
    int waysToClimb = s.climbStairs(n);

    cout << waysToClimb << endl; // prints 8

    return 0;
}