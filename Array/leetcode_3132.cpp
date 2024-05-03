
// Problem Link ====>>https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = INT_MAX;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = i + 1; j < nums1.size(); j++)
            {
                vector<int> updatedNums1;
                for (int k = 0; k < nums1.size(); k++)
                {
                    if (k == i || k == j)
                        continue;
                    updatedNums1.push_back(nums1[k]);
                }
                int flag = 1;
                int diff = nums2[0] - updatedNums1[0];
                for (int k = 1; k < updatedNums1.size(); k++)
                {
                    if (nums2[k] - updatedNums1[k] != diff)
                        flag = 0;
                }
                if (flag)
                    ans = min(ans, nums2[0] - updatedNums1[0]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> nums1;
    vector<int> nums2;
    cout << "Enter elements for the first array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums1[i];
    }

    cout << "Enter elements for the second array:\n";
    for (int j = 0; j < n; ++j)
    {
        cin >> nums2[j];
    }

    int x = s.minimumAddedInteger(nums1, nums2);

    cout << x << endl;
    return 0;
    return 0;
}