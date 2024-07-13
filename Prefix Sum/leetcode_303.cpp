
// Problem link ===>>  https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class NumArray
{
public:
    vector<int> pref;
    vector<int> generatePrefixSum(vector<int> &a)
    {
        int n = a.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];
        return pref;
    }

    NumArray(vector<int> &nums)
    {
        pref.resize(nums.size() + 1);
        pref = generatePrefixSum(nums);
    }

    int sumRange(int left, int right)
    {
        return pref[right + 1] - pref[left];
    }
};

int main()
{
    return 0;
}