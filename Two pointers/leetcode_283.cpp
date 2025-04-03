
// Problem link ===>> https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;
        int n = nums.size();
        
        for (int r = 0; r < n; r++)
        {
            swap(nums[l], nums[r]);
            if (nums[l])
                l++;
        }

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    return 0;
}