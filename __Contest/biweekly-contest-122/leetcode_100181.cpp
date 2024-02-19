#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <climits>
#include <algorithm>

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> minFirst(n, INT_MAX);
        vector<int> minLast(n, INT_MAX);

        // Calculate the minimum cost for the first subarray
        int minCost = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            minCost = min(minCost, nums[i]);
            minFirst[i] = min(minFirst[i], minCost);
        }

        // Calculate the minimum cost for the last subarray
        minCost = INT_MAX;
        for (int i = n - 1; i >= 0; --i)
        {
            minCost = min(minCost, nums[i]);
            minLast[i] = min(minLast[i], minCost);
        }

        // Iterate through the array and find the minimum possible sum
        int result = INT_MAX;
        for (int i = 1; i <= n - 2; ++i)
        {
            int firstCost = minFirst[i - 1];
            int lastCost = minLast[i + 1];
            int currentSum = prefixSum[i] + prefixSum[n] - prefixSum[i] + min(firstCost, lastCost);
            result = min(result, currentSum);
        }

        return result;
    }
};

int main()
{
    vector<int> nums = [ 1, 2, 3, 12 ] // Example input

        Solution solution;
    int minimumCost = solution.minimumCost(nums);

    cout << "Minimum cost: " << minimumCost << endl;

    return 0;
}
