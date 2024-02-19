// Given an integer n, return the number of structurally unique BST's (binary search trees) 
// which has exactly n nodes of unique values from 1 to n.

#include<bits/stdc++.h>
using namespace std;

// Solution - I (Brute-Force) [TLE]

// class Solution
// {
// public:
//     int numTrees(int n)
//     {
//         if (n <= 1)
//             return 1;
//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//             ans += numTrees(i - 1) * numTrees(n - i);
//         return ans;
//     }
// };

// Solution - II (Dynamic Programming - Memoization)
class Solution
{
public:
    int dp[20]{};
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n])
            return dp[n];
        for (int i = 1; i <= n; i++)
            dp[n] += numTrees(i - 1) * numTrees(n - i);
        return dp[n];
    }
};

int main(){
    
    return 0;
}