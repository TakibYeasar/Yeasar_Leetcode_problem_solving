
// Problem link ===>> https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> sum(n + 1);

        for (int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + arr[i - 1];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                int len = j - i + 1;

                if(len%2){
                    ans += (sum[j] - sum[i - 1]);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    return 0;
}