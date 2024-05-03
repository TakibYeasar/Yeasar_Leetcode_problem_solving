
// Problem Link ====>> https://leetcode.com/problems/find-the-integer-added-to-array-i/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums2[0] - nums1[0];
    }
};

int main(){

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

    int x = s.addedInteger(nums1, nums2);

    cout << x << endl;
    return 0;
}