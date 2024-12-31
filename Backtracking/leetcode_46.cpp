
// Problem link ===>>  https://leetcode.com/problems/permutations/description/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int start, vector<vector<int>> &result)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int n; // Declare n to store the size of the input
        cin >> n;
        vector<int> nums(n); // Initialize nums with size n
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<vector<int>> permutations = s.permute(nums);

        // Print the permutations (important to see the output)
        for (const auto &perm : permutations)
        {
            for (int val : perm)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}